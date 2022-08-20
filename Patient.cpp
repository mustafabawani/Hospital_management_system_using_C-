#include "Patient.h"
#include <iostream>
#include<cstdlib> 
#include<ctime> 

using namespace std;

string Patient::getEmailID() {
    return this->emailID;
}
void Patient::setEmailID(string id) {
    this->emailID = id;
}

string Patient::getPass()
{
    return this->pass;
}

void Patient::setPass(string pass)
{
    this->pass = pass;
}
Person Patient::getDetails() {
    return this->details;
}
void Patient::setDetails(Person details) {
    this->details = details;
}

string Patient::getSymptoms() {
    return this->symptoms;
}
void Patient::setSymptoms(string symptoms) {
    this->symptoms = symptoms;
}


string Patient::getPrecautions() {
    return this->precautions;
}
void Patient::setPrecautions(string precautions) {
    this->precautions = precautions;
}


string Patient::getMedications() {
    return this->medications;
}
void Patient::setMedications(string medications) {
    this->medications = medications;
}

static const char alphnum[]="0123456789" "!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz"; 
int strLen=sizeof(alphnum)-1; 
char GenRand()
{ 
    return alphnum[rand()%strLen]; 
}

void Patient::generatePassword()
{
    
    int n=8,c=0,s=0;
    srand(time(0));
        N:
    char C;
    string password;
    for(int z=0; z < n; z++) 
    { 
        C=GenRand();
        password+=C;
        if(isdigit(C))
        {
            c++;
        }
        if(C=='!' || C=='@' || C=='$' || C=='%' ||  C=='^' || C=='&'|| C=='*'|| C=='#')
        {
            s++;
        }
    }
    if(n>2 && (s==0 || c==0))
    {
        goto N; 
    }
    this->pass = password;
}

