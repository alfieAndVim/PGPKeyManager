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