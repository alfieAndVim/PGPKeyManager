#pragma once

#include <gpgme.h>
#include <iostream>

using namespace std;

class KeyParms
{
public:
    KeyParms();
    ~KeyParms();

    string getParms();

    string keyName;
    string keyAlgo;
    int keyLength;
    string keyEmail;
    string keyPassphrase;
    string keyComment;
    long keyExpiry;

    string parmsHeader = "<GnupgKeyParms format=\"internal\">\n";
    string parmsFooter = "</GnupgKeyParms>\n";
};