#ifndef class_admit
#define class_admit
#include "Person.h"
#include "Date.h"
#include "Patient.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

class admit:public Patient
{
    std::string status; // critical, ill, treated
    Date dateOfAdmission;
    Date dateOfDischarge;
    std::string tests;

    public:

    admit();
    admit(string symptoms);

    admit(const admit&);

    std::string getStatus();
    void setStatus(std::string status);

    std::string getTests();
    void setTests(std::string tests);
    
    void addAdmitPatient();
    void updateAdmitPatient(string id,string update);

    Date getDateOfAdmission();
    void setDateOfAdmission(Date dateOfAdmission);

    Date getDateOfDischarge();
    void setDateOfDischarge(Date dateOfDischarge);

    void SearchAdmitPatient(string user);

    void display();

    void readFromFile(ifstream &is);
    void writeInFile(ofstream &os);
};
#endif