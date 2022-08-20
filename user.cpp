#include "user.h"
#include "Doctor.h"
#include "Date.h"
#include "Hospital.h"
#include "Time.h"
#include "globalFunctions.h"
#include <iomanip>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>

using namespace std;

void User::setID(string id)
{
    this->ID = id;
}

string User::getID()
{
    return this->ID;
}

void User::setPassword(string pass)
{
    this->password = pass;
}

string User::getPassword()
{
    return this->password;
}

void User::appoitment(){
 system("cls");
 string name,email,number,drName;
 Time T;
 Date D; 
 int flag=0;
 Doctor doc;
    displayAllDoctor();
cout<<setw(20)<<setfill('*')<<endl;
cout<<setw(20)<<setfill('*')<<endl;
 cout<<"Please Enter Your Name: ";
 cin.ignore();
 getline(cin,name);
 cout<<"Please Enter Your Email id: ";
 getline(cin,email);
 cout<<"Please Enter Your Mobile Number: ";
 getline(cin,number);
 
 cout<<"Please Enter the Doctor Name to book an appoitment: ";
 getline(cin,drName);
 
ifstream is("DoctorData.csv");
    
  while(!is.eof()){
      doc.readFromFile(is);
 if (drName==doc.getName()){
    cout<<"Enter date for appoitment: ";
    cin>>D;
    cout<<"Your request has been submitted"<<endl;
    cout<<"Confirmed time will be emailed to you on "<<email<<endl;
    flag=1;
    break;
 }
}
if(flag=1){
 ofstream os("Appointments.csv");
 os<<name<<","<<email<<","<<number<<","<<drName<<","<<D<<endl;
 os.close();
 }
cout << "Press any key to continue";
_getch();
}

void User::displayAllDoctor(){
    system("cls");
    ifstream is("DoctorData.csv");
    Doctor doc;
    while(!is.eof()){
        doc.readFromFile(is);
        doc.report();
    }
    cout << "Press any key to continue";
    _getch();
}

void User::displayHospitalDetails(){
    system("cls");
    Hospital hos;
    hos.displayGIGAHospital();
    cout << "Press any key to continue";
    _getch();
}

void User::testCorona(){
    char c;
    double yes=0;
    Hospital corona;
    system("cls");
    cout<<"Do you have Fever above 101.4?"<<endl;
    cout<<"Press--Y"<<endl;
    cout<<"Press--N"<<endl;
    cin>>c;
    if(c=='y' || c=='Y')
        yes++;

    cout<<"Do you have Cough - (Dry / Wet Cough)"<<endl;
    cout<<"Press--Y"<<endl;
    cout<<"Press--N"<<endl;
    cin>>c;
    if(c=='y' || c=='Y')
        yes++;

    cout<<"Do you have chest infection??"<<endl;
    cout<<"Press--Y"<<endl;
    cout<<"Press--N"<<endl;
    cin>>c;
    if(c=='y' || c=='Y')
        yes++;

    cout<<"Do you have Shortness of Breath?"<<endl;
    cout<<"Press--Y"<<endl;
    cout<<"Press--N"<<endl;
    cin>>c;
    if(c=='y' || c=='Y')
        yes++;

    cout<<"Do you have Flu?"<<endl;
    cout<<"Press--Y"<<endl;
    cout<<"Press--N"<<endl;
    cin>>c;
    if(c=='y' || c=='Y')
        yes++;

    cout<<"Is your age more than or equal to 60 years of age?"<<endl;
    cout<<"Press--Y"<<endl;
    cout<<"Press--N"<<endl;
    cin>>c;
    if(c=='y' || c=='Y')
        yes++;
    
    system("cls");
    double prob=yes/6*100;
    if(prob>=0 && prob <= 25){
        cout<<"you are at a very low risk. Please practice self-quarantine yourself to stay safe"<<endl;
    }
    else if(prob>25 && prob <=50){
        cout<<"You are at a risk. Please practice self-quarantine yourself to stay safe"<<endl;
    }
    else if(prob>50 && prob <=100){
        cout<<"You are at a very high risk. Practice self-isolation and make sure to get yourself tested at any designated center."<<endl<<endl;
    }
    cout << endl;
    cout<<"For more details contact 1122"<<endl;
    cout<<"Or visit our testing center"<<endl;

    corona.displayAllCoronaHospital();
    cout << "Press any key to continue...";
    _getch();
}


void User::showPatientDetails(string id)
{
    char type;
    int flag = 0;
    cout << "Enter type of Patient: (c for Checkup and a for Admit) ";
    cin >> type;
    system("cls");
    if (type == 'c')
    {
        ifstream is("checkupData.csv");
        check = new checkup;
        while(true)
        {
            check->readFromFile(is);
            if(id==check->getEmailID())
            {
                check->display();
                flag = 1;
                cout << "Press any key to continue...";
                _getch();
                break;
            }
            if(is.eof())
            {
                break;
            }
        }
        is.close();
        delete check;
    }
    if (type == 'a')
    {
        ifstream is("admitData.csv");
        adm = new admit;
        while(true)
        {
            adm->readFromFile(is);
            if(id==adm->getEmailID())
            {
                adm->display();
                flag = 1;
                cout << "Press any key to continue...";
                _getch();
                break;
            }
            if(is.eof())
            {
                break;
            }
        }
        is.close();
        delete adm;
    }
    if(flag==0)
    {
        cout << "No record found." << endl;
        cout << "Press any key to continue";
        _getch();
    }
}

void User::showBillingDetails(string id)
{
    char type;
    int flag = 0;
    cout << "Enter type of Patient: (c for Checkup and a for Admit) ";
    cin >> type;
    system("cls");
    if (type == 'c')
    {
        check = new checkup;
        ifstream is_data("checkupData.csv");
        while(true)
        {
            check->readFromFile(is_data);
            if(check->getEmailID() == id)
            {
                ifstream is_bill("CheckupPatientBill.csv");
                while(true)
                {
                    string temp_data;
                    getline(is_bill, temp_data, ',');
                    if(temp_data == check->getName())
                    {
                        cout << "Name: " << temp_data << endl;
                        getline(is_bill, temp_data, ',');
                        cout << "Checkup Charges: " << temp_data << endl;
                        getline(is_bill, temp_data, ',');
                        cout << "Tax: " << temp_data << endl;
                        getline(is_bill, temp_data);
                        cout << "Total Bill: " << temp_data << endl;
                        flag = 1;
                        break;
                    }
                    else
                    {
                        getline(is_bill, temp_data);
                    }
                    if(is_bill.eof())
                    {
                        break;
                    }
                }
                is_bill.close();
                break;
            }
            if(is_data.eof())
            {
                break;
            }
        }
        is_data.close();
        delete check;
        if(flag==0)
        {
            cout << "No record found." << endl;
        }
        cout << "Press any key to continue...";
        _getch();
        
    }
    if (type == 'a')
    {
        adm = new admit;
        ifstream is_data("admitData.csv");
        while(true)
        {
            adm->readFromFile(is_data);
            if(adm->getEmailID() == id)
            {
                ifstream is_bill("AdmitPatientBill.csv");
                while(true)
                {
                    string temp_data;
                    getline(is_bill, temp_data, ',');
                    if(temp_data == adm->getName())
                    {
                        cout << "Name: " << temp_data << endl;
                        getline(is_bill, temp_data, ',');
                        cout << "Hospital Charges: " << temp_data << endl;
                        getline(is_bill, temp_data, ',');
                        cout << "Test Charges: " << temp_data << endl;
                        getline(is_bill, temp_data, ',');
                        cout << "Bed Charges: " << temp_data << endl;
                        getline(is_bill, temp_data, ',');
                        cout << "Medicine Charges: " << temp_data << endl;
                        getline(is_bill, temp_data, ',');
                        getline(is_bill, temp_data, ',');
                        cout << "Tax: " << temp_data << endl;
                        getline(is_bill, temp_data, ',');
                        cout << "Total Bill: " << temp_data << endl;
                        flag = 1;
                        break;
                    }
                    else
                    {
                        getline(is_bill, temp_data);
                    }
                    if(is_bill.eof())
                    {
                        break;
                    }
                }
                is_bill.close();
                break;
            }
            if(is_data.eof())
            {
                break;
            }
        }
        is_data.close();
        delete adm;
        if(flag==0)
        {
            cout << "No record found." << endl;
        }
        cout << "Press any key to continue...";
        _getch();
        
    }
}