#ifndef CLASS_Admin
#define CLASS_Admin
#include "Doctor.h"
#include "Patient.h"
#include "checkup.h"
#include "admit.h"
#include "Person.h"
#include "Date.h"
#include <fstream>
#include <iostream>
#include <string>



class Admin{
    std::string id;
    std::string pass;
    
public:
    Admin();
    std::string getID();
    void setID(std::string id);
    std::string getPass();
    void setPass(std::string pass);
    void addDoctorData();
    void updateDoctorData();
    void deleteDoctorData();
    void searchDoctorData();
    void displayAllDoctor();
    void addCheckupPatientData();
    void addAdmitPatientData();
    void updateCheckupPatientData();
    void updateAdmitPatientData();
    void searchCheckupPatient();
    void searchAdmitPatient();
    void billCheckupPatient();
    void billAdmitPatient();
    
};
#endif
