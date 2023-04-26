//Ensuring the header file is included only once during compilation
#pragma once
//Including the necessary header files
#include <gpgme.h>
#include <vector>
#include <string>
#include <iostream>
#include <KeyParms.h>

//Using the standard namespace
using namespace std;

//Defining the GpgmeRepo class
class GpgmeRepo
{

//Defining the GpgmeRepo constructor
public:
    GpgmeRepo();
    ~GpgmeRepo();

    //Defining the GpgmeRepo methods
    gpgme_genkey_result_t GenerateKeyPair(KeyParms parms);
    vector<gpgme_key_t> GetKeys();
    vector<gpgme_key_t> GetSecretKeys();
    gpgme_key_t GetKeyById(string id);
    gpgme_key_t GetSecretKeyById(string id);
    string GetKeyBlock(gpgme_key_t key, bool secret = false);
    void DeleteKey(gpgme_key_t key);
    gpgme_import_result_t ImportKey(string filePath);
    void SignKey(gpgme_key_t key, gpgme_key_t signingKey, long expiry);
    

private:
    //Defining the GpgmeRepo context for gpgme
    gpgme_ctx_t ctx = nullptr;
};