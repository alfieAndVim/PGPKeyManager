#pragma once

#include <gpgme.h>
#include <vector>

using namespace std;

class GpgmeRepo
{

public:
    GpgmeRepo();
    ~GpgmeRepo();

    vector<gpgme_key_t> GetKeys();

private:
    gpgme_ctx_t ctx = nullptr;
};