#ifndef class_checkup
#define class_checkup
#include "Person.h"
#include "Date.h"
#include "Patient.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

class checkup:public Patient
{

    Date dateOfCheckup;

    public:
    checkup();
    checkup(std::string symptoms);

    checkup(const checkup &);

    Date getDateOfCheckup();
    void setDateOfCheckup(Date dateOfCheckup);

    void addCheckupPatient();

    void updateCheckupPatient(std::string user , std::string update);

    void SearchCheckupPatient(string user);

    void display();

    void readFromFile(ifstream &is);

    void writeInFile(ofstream &os);

};
#endif