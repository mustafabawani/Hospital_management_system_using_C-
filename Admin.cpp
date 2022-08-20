#include "Admin.h"
#include "Doctor.h"
#include "Person.h"
#include "Date.h"
#include <fstream>
#include <iostream>
#include <string>
#include "globalFunctions.h"
#include <algorithm>
#include <Windows.h>
#include <conio.h>
#include "Time.h"

using namespace std;

Admin::Admin(){
    id = "admin";
    pass = "adminpass";
    doc=new Doctor;
    check = new checkup;
    adm = new admit;
}

string Admin::getID()
{
    return this->id;
}

void Admin::setID(string id)
{
    this->id = id;
}

string Admin::getPass()
{
    return this->pass;
}
void Admin::setPass(string pass)
{
    this->pass = pass;
}
void Admin::addDoctorData(){
        bool check;
        doc->addDoctorData();
        check=doc->writeInFile();
    if(check=true){
        cout<<"Data sucessfully written"<<endl;
    }
    else    
        cout<<"Unsuccesful!!!"<<endl;
}

void Admin::updateDoctorData(){
    string new_data;
    int new_int;
    string update;
    int pos;
    int flag=0;
    string n;

    //taking name of doctor to update its data
    cout<<"Enter doctor name: ";
    cin.ignore();
    getline(cin,n);

    //transform name to lower case
    transform(n.begin(), n.end(), n.begin(), ::tolower);
    //taking attribute to change
    cout<<"Enter the doctor's attribute you want to change: ";
    cin>>update;

    transform(update.begin(), update.end(), update.begin(), ::tolower);
    //taking new data 
    Time time;
    if(update=="name" || update=="address" || update=="mobile" || update=="practicehour"){
    cout<<"Enter new " << update << " to update: " ;
    cin.ignore();
    getline(cin,new_data);
    }

    else if(update=="fees"){
        cout<<"Enter updated fees"<<endl;
        cin>>new_int;
    }

    
    else if(update=="practice start hours")
    {
        cout << "Enter New Starting hour: ";
        cin >> time;
        doc->setPracticeStartHours(time);
    }
    else if(update=="practiceendhours")
    {
        cout << "Enter New Ending hour: ";
        cin >> time;
        doc->setPracticeEndHours(time);
    }
    
    ifstream is ("DoctorData.csv");
    ofstream os ("temp.csv");
    doc->readFromFile(is);
    while(is)
    {
        
        //finding name in file 
        if(doc->getName()==n)
        {
            flag=1;
            if(update=="name")
            {
                doc->setName(new_data);
            }
            else if(update=="address")
            {
                cout << "address";
                doc->setAddress(new_data);
            }
            
            else if(update=="mobile")
            {
                doc->setMobile(new_data);
            }
           
            
            else if(update=="fees"){
                
                doc->setFee(new_int);
            }
                
        }
            os<<doc->getName()<<","<<doc->getAddress()<<","<<doc->getAge()<<","<<doc->getGender()<<","<<doc->getCnic()<<","<<doc->getMobile()<<","<<doc->getDob()<<",";
            os<<doc->getType()<<","<<doc->getSpecialization()<<","<<doc->getFee()<<","<<doc->getPracticeStartHours()<<","<<doc->getPracticeEndHours()<<"\n";
        doc->readFromFile(is);
        
    }

    os.close();
    is.close();
    
    remove("DoctorData.csv");
    rename("temp.csv","DoctorData.csv");
    deleteEmptyLinesFromDoctorFile();
        if(flag==0)
            cout<<"Record Not Found!!!"<<endl;
        
        else{
            cout<<"Record updated successfully"<<endl;
           
        }
        Sleep(1000);

}

void Admin::deleteDoctorData(){
    
      
    ifstream is;
    ofstream os;
    
    string n;
    int flag=0;

    cin.ignore();
    
    cout<<"Enter the Name of Doctor"<<endl;

    
    getline(cin,n); 
    transform(n.begin(), n.end(), n.begin(), ::tolower);
    is.open("DoctorData.csv");
    os.open("temp.csv");

    doc->readFromFile(is);
           
    while(is){
        if(doc->getName()!=n){
            os<<doc->getName()<<","<<doc->getAddress()<<","<<doc->getAge()<<","<<doc->getGender()<<","<<doc->getCnic()<<","<<doc->getMobile()<<","<<doc->getDob()<<",";
            os<<doc->getType()<<","<<doc->getSpecialization()<<","<<doc->getFee()<<","<<doc->getPracticeStartHours()<<","<<doc->getPracticeEndHours()<<"\n";
        }
        else{
            flag=1;
        }
        doc->readFromFile(is);
    }
    is.close();
    os.close();
    remove("DoctorData.csv");
    rename("temp.csv","DoctorData.csv");
    deleteEmptyLinesFromDoctorFile();

    //check if data is succesgully removed
    if(flag==0)
        cout<<"Record Not Found!!!"<<endl;
    else
        cout<<"Record deleted successfully"<<endl;
    Sleep(1000);
   
}


void Admin::searchDoctorData(){
    string n;

    cout<<"Enter the name of doctor: "<<endl;
    cin.ignore();
    getline(cin,n);
    // transform(n.begin(), n.end(), n.begin(), ::tolower);

    int flag=0;
    ifstream is;
    is.open("DoctorData.csv");

    doc->readFromFile(is);

    while (is)   
    {   
        
        if(doc->getName()==n){
        doc->displayDoctorData();
        flag=1;
        } 
        doc->readFromFile(is);
     
    }
    if(flag==0)
        cout<<"No doctor found!!!"<<endl;
    cout << "Press any key to continue...";
    _getch();
}

void Admin::displayAllDoctor(){
    ifstream is("DoctorData.csv");
    while(!is.eof()){
        doc->readFromFile(is);
        doc->report();
    }
    cout << "Press any key to continue...";
    _getch();
}

void Admin::addAdmitPatientData()
{
    adm->addAdmitPatient();
    ofstream os("admitData.csv", ios::app); 
    adm->writeInFile(os);
    os.close();
    loading();
    system("cls");
    adm->generatePassword();
    os.open("patientlogin(encrypted).csv", ios::app);
    os << adm->getEmailID() << "," << encrypt(adm->getPass()) << endl;
    os.close();
    cout << "Patient Added Successfully!!" << endl;
    cout << "Use Email ID and Password generated below to login:" << endl;
    cout << "Generated Password for " << adm->getEmailID() << ": " << endl;
    cout << "\t\t\t" << adm->getPass() << endl;
    cout << "Please note down this password, you can change this password after logging in to your account." << endl;
    cout << "Press any key to continue..";
    _getch();
}

void Admin::addCheckupPatientData()
{
    check->addCheckupPatient();
    ofstream os("checkupData.csv", ios::app); 
    check->writeInFile(os);
    os.close();
    loading();
    system("cls");
    check->generatePassword();
    os.open("patientlogin(encrypted).csv", ios::app);
    os << check->getEmailID() << "," << encrypt(check->getPass()) << endl;
    os.close();
    cout << "Patient Added Successfully!!" << endl;
    cout << "Use Email ID and Password generated below to login:" << endl;
    cout << "Generated Password for " << check->getEmailID() << ": " << endl;
    cout << "\t\t\t" << check->getPass() << endl;
    cout << "Please note down this password, you can change this password after logging in to your account." << endl;
    cout << "Press any key to continue..";
    _getch();
}

void Admin::updateCheckupPatientData()
{
    string user, update;
    system("cls");
    cout << "Enter Patient's name: ";
    cin.ignore();
    getline(cin, user);
    while(true)
    {
        cout << "Enter Field to update: ";
        getline(cin, update);
        transform(update.begin(), update.end(), update.begin(), ::tolower);
        if(update == "name" || update == "age" || update=="address" || update=="mobile" || update=="precautions" || update=="medications" || update=="email")
        {
            check->updateCheckupPatient(user, update);
            break;
        }
        else
            cout << "Invalid Field!!" << endl;
        Sleep(1000);
    }

}

void Admin::updateAdmitPatientData()
{
    string user, update;
    system("cls");
    cout << "Enter Patient's name: ";
    cin.ignore();
    getline(cin, user);
    while(true)
    {
        cout << "Enter Field to update: ";
        getline(cin, update);
        if(update == "name" || update == "age" || update=="address" || update=="mobile" || update=="precautions" || update=="medications" || update=="tests" || update=="status")
        {
            adm->updateAdmitPatient(user, update);
            Sleep(1000);
            break;
        }
        else
            cout << "Invalid Field!!" << endl;
        Sleep(1000);
    }
}

void Admin::searchAdmitPatient()
{
    string user;
    system("cls");
    cout << "Enter Patient's name: ";
    cin.ignore();
    getline(cin, user);
    adm->SearchAdmitPatient(user);
    cout << "Press any key to go back.";
    _getch();

}

void Admin::searchCheckupPatient()
{
    string user;
    system("cls");
    cout << "Enter Patient's name: ";
    cin.ignore();
    getline(cin, user);
    check->SearchCheckupPatient(user);
    cout << "Press any key to go back.";
    _getch();

}

void Admin::billAdmitPatient()
{
    acc = new Accountant;
    adm = new admit;
    string name;
    cout << "Enter Patient's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Patient's Details: " << endl;
    adm->updateAdmitPatient(name, "date of discharge");
    cin.ignore();
    adm->updateAdmitPatient(name, "status");
    acc->total_admit_bill(name);
    cout << "Press any key to continue...";
    _getch();
}

void Admin::billCheckupPatient()
{
    acc = new Accountant;
    check = new checkup;
    string name;
    cout << "Enter Patient's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Patient's Details: " << endl;
    acc->total_checkup_bill(name);
    cout << "Press any key to continue...";
    _getch();
}
