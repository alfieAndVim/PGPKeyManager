///////////////////////////////////////////////////////////
//Progamming Languages in Cyber Security - CW2 - U2138875//
///////////////////////////////////////////////////////////

//Ensuring the header file is included only once during compilation
#pragma once

//Including the necessary header files
#include <iostream>

//Using the standard namespace
using namespace std;

//Defining the KeySignature struct
struct KeySignature{
    string signatureEmail;
    string signatureName;
    string signatureComment;
    long signatureExpiration;
};
