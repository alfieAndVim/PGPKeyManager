///////////////////////////////////////////////////////////
//Progamming Languages in Cyber Security - CW2 - U2138875//
///////////////////////////////////////////////////////////

//Ensuring the header file is included only once during compilation
#pragma once

//Including the necessary header files
#include <gpgme.h>
#include <iostream>

//Using the standard namespace
using namespace std;

//Defining the KeyParms class
class KeyParms
{
public:
    KeyParms();
    ~KeyParms();

    //Defining the KeyParms methods
    string getParms();

    //Defining the KeyParms variables
    string keyName;
    string keyAlgo;
    int keyLength;
    string keyEmail;
    string keyPassphrase;
    string keyComment;
    string keyExpiry;

    string parmsHeader = "<GnupgKeyParms format=\"internal\">\n";
    string parmsFooter = "</GnupgKeyParms>\n";
};