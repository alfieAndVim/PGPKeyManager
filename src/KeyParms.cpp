#include <KeyParms.h>

KeyParms::KeyParms()
{
}

string KeyParms::getParms()
{
    string parms = parmsHeader;
    parms += "Key-Type: " + keyAlgo + "\n";
    parms += "Key-Length: " + to_string(keyLength) + "\n";
    parms += "Subkey-Type: " + keyAlgo + "\n";
    parms += "Subkey-Length: " + to_string(keyLength) + "\n";
    parms += "Name-Real: " + keyName + "\n";
    parms += "Name-Comment: " + keyComment + "\n";
    parms += "Name-Email: " + keyEmail + "\n";
    parms += "Expire-Date: " + keyExpiry + "\n";
    parms += "Passphrase: " + keyPassphrase + "\n";
    parms += parmsFooter;
    return parms;
}

KeyParms::~KeyParms()
{
}