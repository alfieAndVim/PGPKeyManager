#pragma once

#include <gpgme.h>
#include <vector>
#include <string>
#include <KeyParms.h>

using namespace std;

class GpgmeRepo
{

public:
    GpgmeRepo();
    ~GpgmeRepo();

    gpgme_genkey_result_t GenerateKeyPair(KeyParms parms);
    vector<gpgme_key_t> GetKeys();
    vector<gpgme_key_t> GetSecretKeys();
    gpgme_key_t GetKeyById(string id);
    gpgme_key_t GetSecretKeyById(string id);
    string GetKeyBlock(gpgme_key_t key, bool secret = false);
    void DeleteKey(gpgme_key_t key);
    gpgme_import_result_t ImportKey(string filePath);
    void SignKey(gpgme_key_t key, gpgme_key_t signingKey, int expiry);
    

private:
    gpgme_ctx_t ctx = nullptr;
};