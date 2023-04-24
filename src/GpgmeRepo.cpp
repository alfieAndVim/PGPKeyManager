#include <GpgmeRepo.h>
#include <iostream>

using namespace std;

GpgmeRepo::GpgmeRepo()
{
    gpgme_check_version(NULL);
    gpgme_engine_check_version(GPGME_PROTOCOL_OpenPGP);
    gpgme_new(&ctx);
    gpgme_set_protocol(ctx, GPGME_PROTOCOL_OpenPGP);
    gpgme_set_armor(ctx, 1);
    
}

GpgmeRepo::~GpgmeRepo()
{
    gpgme_release(ctx);
}

gpgme_genkey_result_t GpgmeRepo::GenerateKeyPair(KeyParms parms)
{
    gpgme_error_t err;

    string str_parms = parms.getParms();

    gpgme_genkey_result_t result;

    err = gpgme_op_genkey(ctx, str_parms.c_str(), NULL, NULL);

    if (err != GPG_ERR_NO_ERROR)
    {
        throw "Error generating key";
    }

    result = gpgme_op_genkey_result(ctx);

    return result;
}

vector<gpgme_key_t> GpgmeRepo::GetKeys()
{
    gpgme_key_t key;
    gpgme_key_t keylist;
    gpgme_error_t err;
    vector<gpgme_key_t> keys;

    err = gpgme_op_keylist_start(ctx, NULL, 0);
    if (err != GPG_ERR_NO_ERROR)
    {
        return keys;
    }

    while (true)
    {
        err = gpgme_op_keylist_next(ctx, &key);
        if (err != GPG_ERR_NO_ERROR)
        {
            break;
        }
        keys.push_back(key);
    }

    gpgme_op_keylist_end(ctx);

    return keys;
}

vector<gpgme_key_t> GpgmeRepo::GetSecretKeys()
{
    gpgme_key_t key;
    gpgme_key_t keylist;
    gpgme_error_t err;
    vector<gpgme_key_t> keys;

    err = gpgme_op_keylist_start(ctx, NULL, 1);
    if (err != GPG_ERR_NO_ERROR)
    {
        return keys;
    }

    while (true)
    {
        err = gpgme_op_keylist_next(ctx, &key);
        if (err != GPG_ERR_NO_ERROR)
        {
            break;
        }
        keys.push_back(key);
    }

    gpgme_op_keylist_end(ctx);

    return keys;
}

gpgme_key_t GpgmeRepo::GetKeyById(string id)
{
    gpgme_key_t key;
    gpgme_error_t err;

    err = gpgme_get_key(ctx, id.c_str(), &key, 0);
    if (err != GPG_ERR_NO_ERROR)
    {
        throw "Key not found";
    }

    return key;
}

gpgme_key_t GpgmeRepo::GetSecretKeyById(string id)
{
    gpgme_key_t key;
    gpgme_error_t err;

    err = gpgme_get_key(ctx, id.c_str(), &key, 1);
    if (err != GPG_ERR_NO_ERROR)
    {
        throw "Key not found";
    }

    return key;
}

string GpgmeRepo::GetKeyBlock(gpgme_key_t key, bool secret)
{
    gpgme_data_t data;
    gpgme_error_t err;
    char *buffer;
    size_t size;

    gpgme_data_new(&data);

    if (secret)
    {
        err = gpgme_op_export(ctx, key->subkeys->keyid, GPGME_EXPORT_MODE_SECRET, data);
    } else {
        err = gpgme_op_export(ctx, key->subkeys->keyid, 0, data);
    }

    if (err != GPG_ERR_NO_ERROR)
    {
        throw "Error exporting key";
    }

    size = gpgme_data_seek(data, 0, SEEK_END);
    gpgme_data_seek(data, 0, SEEK_SET);
    buffer = new char[size + 1];
    gpgme_data_read(data, buffer, size);
    buffer[size] = '\0';

    string keyBlock(buffer);

    delete[] buffer;
    gpgme_data_release(data);

    return keyBlock;
}

void GpgmeRepo::DeleteKey(gpgme_key_t key)
{
    gpgme_error_t err;

    err = gpgme_op_delete(ctx, key, GPGME_DELETE_ALLOW_SECRET);
    if (err != GPG_ERR_NO_ERROR)
    {
        throw "Error deleting key";
    }
}

gpgme_import_result_t GpgmeRepo::ImportKey(string filePath)
{
    gpgme_data_t keydata;
    gpgme_error_t err;
    gpgme_import_result_t result;

    err = gpgme_data_new_from_file(&keydata, filePath.c_str(), 1);

    if (err != GPG_ERR_NO_ERROR)
    {
        throw "Error retrieving key from file";
    }

    err = gpgme_op_import_start(ctx, keydata);

    if (err != GPG_ERR_NO_ERROR)
    {
        throw "Error beginning import of key";
    }

    gpgme_wait(ctx, &err, true);

    if (err != GPG_ERR_NO_ERROR)
    {
        throw "Error completing import";
    }

    result = gpgme_op_import_result(ctx);

    gpgme_data_release(keydata);

    return result;
}

void GpgmeRepo::SignKey(gpgme_key_t key, gpgme_key_t signingKey, int expiry)
{
    gpgme_error_t err;

    gpgme_signers_clear(ctx);

    cout << gpgme_signers_count(ctx) << endl;

    err = gpgme_signers_add(ctx, signingKey);

    cout << gpgme_signers_count(ctx) << endl;

    if (err != GPG_ERR_NO_ERROR)
    {
        cout << gpgme_strerror(err) << endl;
        throw "Error adding signer";
    }

    cout << "Signing key: " << signingKey->subkeys->keyid << endl;

    string userId = key->uids->uid;

    cout << "Signing user: " << userId << endl;

    err = gpgme_op_keysign_start(ctx, key, userId.c_str(), 0, GPGME_KEYSIGN_FORCE);

    if (err != GPG_ERR_NO_ERROR)
    {
        cout << gpgme_strerror(err) << endl;
        throw "Error signing key";
    }

    gpgme_wait(ctx, &err, true);

    if (err != GPG_ERR_NO_ERROR)
    {
        cout << gpgme_strerror(err) << endl;
        throw "Error completing signing";
    }

    gpgme_signers_clear(ctx);
}
