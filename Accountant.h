#ifndef class_Accountant
#define class_Accountant
//#include "Patient.h"
//#include "checkup.h"
#include <vector>
#include"admit.h"
#include "Doctor.h"
#include "Admin.h"
#include "Person.h"
#include "Date.h"
#include "Patient.h"
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
class Accountant
{
    float const hospital_charges=3000;
    float const rate=0.025;
    double TotalBedCharges;
    double medicine_charges;
    double test_charges;
    double total_bill;
    double totalAdmitBill;
    double checkupCharges;
    double admitCharges;
    double totalCheckupBill;
    bool paid_bill;
    double tax;
    double hospital_revenue;

    Accountant(const Accountant &);

    public:
    Accountant();

    void setTotalBedCharges(string room);
    double getTotalBedCharges();

    void setMedicineCharges(double);
    double getMedicineCharges();

    void setTestCharges(string name);
    double getTestCharges();

    void setAdmitCharges(string name);
    double getAdmitCharges();

    void setCheckupCharges(string doctor);
    double getCheckupCharges();
    
    void set_tax(double total);
    double get_tax();


    void total_checkup_bill(std::string name);
    
    void total_admit_bill(std::string name);
    
    void display_bill(string name,double amount,double charges);

    void display_bill(string name,double amount); //Function overloading

    void total_hospital_revenue();

    double getTotalRevenue();

    void displayHospitalRevenue();
};
#endif