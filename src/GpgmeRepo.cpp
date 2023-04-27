//including header file for the gpgme repo class
#include <GpgmeRepo.h>

//using the standard namespace
using namespace std;

//constructor and destructor for the gpgme repo class
GpgmeRepo::GpgmeRepo()
{
    //checking the version of the gpgme library
    gpgme_check_version(NULL);
    gpgme_engine_check_version(GPGME_PROTOCOL_OpenPGP);
    //generating a new context for the gpgme library
    gpgme_new(&ctx);
    //setting the protocol to OpenPGP
    gpgme_set_protocol(ctx, GPGME_PROTOCOL_OpenPGP);
    //setting the use of ascii armor to true
    gpgme_set_armor(ctx, 1);
    
}

GpgmeRepo::~GpgmeRepo()
{
    //releasing the context from memory
    gpgme_release(ctx);
}

//function to generate a key pair using the KeyParms class
gpgme_genkey_result_t GpgmeRepo::GenerateKeyPair(KeyParms parms)
{
    //declaring the error variable
    gpgme_error_t err;

    //getting the parameters from the KeyParms class
    string str_parms = parms.getParms();

    cout << "got parms" << endl;

    //declaring the result variable
    gpgme_genkey_result_t result;

    //generating the key pair
    err = gpgme_op_genkey(ctx, str_parms.c_str(), NULL, NULL);

    cout << "generated key" << endl;

    //checking for errors from the key generation
    if (err != GPG_ERR_NO_ERROR)
    {
        cout << gpgme_strerror(err) << endl;
        throw err;
    }

    //getting the result of the key generation
    result = gpgme_op_genkey_result(ctx);

    //returning the result of the generated key
    return result;
}

//function to return the keys from the gpg keyring
vector<gpgme_key_t> GpgmeRepo::GetKeys()
{
    //declaring the key variables
    gpgme_key_t key;
    gpgme_key_t keylist;
    gpgme_error_t err;
    //declaring the vector of keys
    vector<gpgme_key_t> keys;

    gpgme_set_keylist_mode(ctx, GPGME_KEYLIST_MODE_SIGS);

    //starting the key list operation with the context
    err = gpgme_op_keylist_start(ctx, NULL, 0);
    if (err != GPG_ERR_NO_ERROR)
    {
        return keys;
    }

    //looping through the keys and adding them to the vector
    while (true)
    {
        err = gpgme_op_keylist_next(ctx, &key);
        if (err != GPG_ERR_NO_ERROR)
        {
            break;
        }
        keys.push_back(key);
    }

    //ending the key list operation
    gpgme_op_keylist_end(ctx);

    //returning the vector of keys
    return keys;
}

//function to return the secret keys from the gpg keyring
vector<gpgme_key_t> GpgmeRepo::GetSecretKeys()
{
    //declaring the key variables
    gpgme_key_t key;
    gpgme_key_t keylist;
    gpgme_error_t err;
    vector<gpgme_key_t> keys;

    //starting the key list operation with the context, secret keys only
    err = gpgme_op_keylist_start(ctx, NULL, 1);
    if (err != GPG_ERR_NO_ERROR)
    {
        return keys;
    }

    //looping through the keys and adding them to the vector
    while (true)
    {
        err = gpgme_op_keylist_next(ctx, &key);
        if (err != GPG_ERR_NO_ERROR)
        {
            break;
        }
        keys.push_back(key);
    }

    //ending the key list operation
    gpgme_op_keylist_end(ctx);

    //returning the vector of keys
    return keys;
}

//function to return the key by id
gpgme_key_t GpgmeRepo::GetKeyById(string id)
{
    //declaring the key variable
    gpgme_key_t key;
    gpgme_error_t err;

    //getting the key by id, secret flag set to false
    err = gpgme_get_key(ctx, id.c_str(), &key, 0);
    if (err != GPG_ERR_NO_ERROR)
    {
        throw err;
    }

    //returning the key
    return key;
}

//function to return the secret key by id
gpgme_key_t GpgmeRepo::GetSecretKeyById(string id)
{
    //declaring the key variable
    gpgme_key_t key;
    gpgme_error_t err;

    //getting the key by id, secret flag set to true
    err = gpgme_get_key(ctx, id.c_str(), &key, 1);
    if (err != GPG_ERR_NO_ERROR)
    {
        throw err;
    }

    //returning the key
    return key;
}

//function to return the key block for a given key object
string GpgmeRepo::GetKeyBlock(gpgme_key_t key, bool secret)
{
    //declaring the data variable
    gpgme_data_t data;
    //declaring the error variable
    gpgme_error_t err;
    //declaring the buffer variable
    char *buffer;
    //declaring the size variable for the buffer
    size_t size;

    //creating a new data object
    gpgme_data_new(&data);

    //exporting the key data to the data object
    if (secret)
    {
        err = gpgme_op_export(ctx, key->subkeys->keyid, GPGME_EXPORT_MODE_SECRET, data);
    } else {
        err = gpgme_op_export(ctx, key->subkeys->keyid, 0, data);
    }

    if (err != GPG_ERR_NO_ERROR)
    {
        throw err;
    }

    //getting the size of the data object
    size = gpgme_data_seek(data, 0, SEEK_END);
    //resetting the seek position of the data object
    gpgme_data_seek(data, 0, SEEK_SET);
    //allocating the buffer
    buffer = new char[size + 1];
    //reading the data into the buffer
    gpgme_data_read(data, buffer, size);
    //adding the null terminator to the buffer
    buffer[size] = '\0';

    //creating the key block string
    string keyBlock(buffer);

    //freeing the buffer and releasing the data object
    delete[] buffer;
    gpgme_data_release(data);

    //returning the key block string
    return keyBlock;
}

//function to delete a key from a given key object
void GpgmeRepo::DeleteKey(gpgme_key_t key)
{
    //declaring the error variable
    gpgme_error_t err;

    //deleting the key, allowing the secret key to be deleted as well
    err = gpgme_op_delete(ctx, key, GPGME_DELETE_ALLOW_SECRET);
    if (err != GPG_ERR_NO_ERROR)
    {
        throw err;
    }
}

//function to import a key from a given file path
gpgme_import_result_t GpgmeRepo::ImportKey(string filePath)
{
    //declaring the key data variable
    gpgme_data_t keydata;
    //declaring the error variable
    gpgme_error_t err;
    //declaring the result variable
    gpgme_import_result_t result;

    //creating a new data object from the file path
    err = gpgme_data_new_from_file(&keydata, filePath.c_str(), 1);

    //checking for errors
    if (err != GPG_ERR_NO_ERROR)
    {
        throw err;
    }

    //starting the import operation
    err = gpgme_op_import_start(ctx, keydata);

    if (err != GPG_ERR_NO_ERROR)
    {
        throw err;
    }

    //waiting on the import operation to complete
    gpgme_wait(ctx, &err, true);

    if (err != GPG_ERR_NO_ERROR)
    {
        throw err;
    }

    //getting the import result
    result = gpgme_op_import_result(ctx);

    //releasing the key data
    gpgme_data_release(keydata);

    //returning the import result
    return result;
}

//function to sign a key given the signing and key objects
void GpgmeRepo::SignKey(gpgme_key_t key, gpgme_key_t signingKey, long expiry)
{

    //declaring the error variable
    gpgme_error_t err;

    //clearing the previous signers
    gpgme_signers_clear(ctx);

    //adding the signing key as a signer
    err = gpgme_signers_add(ctx, signingKey);

    //checking for errors
    if (err != GPG_ERR_NO_ERROR)
    {
        cout << gpgme_strerror(err) << endl;
        throw err;
    }

    //signing the key
    string userId = key->uids->uid;

    //starting the signing operation
    err = gpgme_op_keysign_start(ctx, key, userId.c_str(), expiry, GPGME_KEYSIGN_FORCE);

    //checking for errors
    if (err != GPG_ERR_NO_ERROR)
    {
        cout << gpgme_strerror(err) << endl;
        throw err;
    }

    //waiting on the signing operation to complete
    gpgme_wait(ctx, &err, true);

    //checking for errors
    if (err != GPG_ERR_NO_ERROR)
    {
        cout << gpgme_strerror(err) << endl;
        throw err;
    }

    //clearing the signers
    gpgme_signers_clear(ctx);
}
