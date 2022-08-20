#include <iostream>
#include <conio.h>
#include <algorithm>
#include <string>
#include"admit.h"
#include "globalFunctions.h"

admit::admit(){
    
}

admit::admit(string symptoms){
    setSymptoms(symptoms);
}

admit::admit(const admit &a):Patient(a)
{
   status=a.status;
   dateOfDischarge= a.dateOfDischarge;
   dateOfAdmission=a.dateOfAdmission;
   tests=a.tests;
}

std::string admit::getStatus() {
    return this->status;
}
void admit::setStatus(std::string status) {
    this->status = status;
}

std::string admit::getTests() {
    return this->tests;
}
void admit::setTests(std::string tests) {
    this->tests = tests;
}

Date admit::getDateOfAdmission() {
	return this->dateOfAdmission;
}
void admit::setDateOfAdmission(Date dateOfAdmission) {
	this->dateOfAdmission = dateOfAdmission;
}


Date admit::getDateOfDischarge() {
    return this->dateOfDischarge;
}
void admit::setDateOfDischarge(Date dateOfDischarge) {
    this->dateOfDischarge = dateOfDischarge;
}

void admit::addAdmitPatient()
{
    int user_age;
    char ch;
    string user;
    system("cls");
    Date d;
    cout << "Please Enter Patient Details:-" << endl;
    cin.ignore();
    cout << "Enter name: ";     
    getline(cin,user);      setName(user);
    while(!is_valid_name(user)){
        cout<<"Invalid Input. Please enter correct name: ";
        getline(cin,user);    setName(user);
        }

    cout << "Enter Address: ";
    getline(cin,user);      setAddress(user);

    cout<<"Enter Age: ";
    cin>>user_age;      cin.ignore();   setAge(user_age);
    
    cout<<"Enter Gender (Male=m / Female=f): ";
    cin >> ch;  setGender(ch);
    cin.ignore();
    
    cout<<"Enter CNIC Number (12101-*******-*): ";
    getline(cin,user);      setCnic(user);
    while(!is_valid_CNIC(user)){
        cout<<"Invalid Input. Please enter correct CNIC number: ";
        getline(cin,user);    setCnic(user);
        }
    
    cout<<"Enter Mobile Number (+923YZXXXXXXX): ";
    getline(cin,user);  setMobile(user);
    while(!is_valid_number(user)){
        cout<<"Invalid Input. Please enter correct mobile number: ";
        getline(cin,user);    setMobile(user);
        }

    cout<<"Enter Email ID: ";
    getline(cin,user);      setEmailID(user);
    while(!is_valid_email(user)){
        cout<<"Invalid Input. Please enter correct emailID: ";
        getline(cin,user);    setEmailID(user);
    }

    cout << "Enter Patient Date of Birth: " ;
    cin>>d;     setDob(d);
    while(!is_valid_date(d)){
        cout<<"Invalid Input. Please enter correct date: ";
        cin>>d;    setDob(d);
        }
    
    cin.ignore();
    cout << "Enter Status: ";
    getline(cin,user);
    setStatus(user);
    cout << "Enter Symptoms: ";
    getline(cin,user);
    replace(user.begin(), user.end(), ',', '|');
    setSymptoms(user);

    cout << "Enter Date of Admit: " ;
    cin>>d;     setDateOfAdmission(d);
    while(!is_valid_date(d)){
        cout<<"Invalid Input. Please enter correct date: ";
        cin>>d;    setDateOfAdmission(d);
        }
}

void admit::updateAdmitPatient(string user,string update)
{

    int flag=0;
    transform(update.begin(), update.end(), update.begin(), ::tolower);
    admit temp;
    ofstream os("tempData.csv");
    ifstream is ("admitData.csv");
    temp.readFromFile(is);
    while(true)
    {
        if(is.eof())
        {
            break;
        }
        if(temp.getName()==user)
        {
            string new_data;
            int new_age;
            cout << "Enter " << update << " to update: ";
            if (update == "age")
            {
                cin >> new_age;
                temp.setAge(new_age);
            }
            else if (update == "date of discharge")
            {
                Date date;
                cin >> date;
                temp.setDateOfDischarge(date);
            }
            else
            {
                getline(cin,new_data);
                replace(new_data.begin(), new_data.end(), ',', '|');
                if(update=="name")
                {
                    temp.setName(new_data);
                }
                if(update=="email")
                {
                    temp.setEmailID(new_data);
                }
                if(update=="address")
                {
                    temp.setAddress(new_data);
                }            
                if(update=="mobile")
                {
                    temp.setMobile(new_data);
                }
                if(update=="precautions")
                {
                    temp.setPrecautions(new_data);
                }
                if(update=="medications")
                {
                    temp.setMedications(new_data);
                }
                if(update=="tests")
                {
                    temp.setTests(new_data);
                }
                if(update=="status")
                {
                    temp.setStatus(new_data);
                }
            }
            flag=1;
        }
        temp.writeInFile(os);
        temp.readFromFile(is);
    }
    is.close();
    os.close();
    remove("admitData.csv");
    rename("tempData.csv","admitData.csv");
    if(flag==0)
        cout<<"Record Not Found!!!"<<endl;
    else
        cout << "Record updated successfully!!!" << endl;
}

void admit::SearchAdmitPatient(string user)
{
    int flag=0;
    admit temp;
    ifstream is ("admitData.csv");
    while(true)
    {
        temp.readFromFile(is);
        if(temp.getName()==user)
        {
            temp.display();
            flag=1;
            break;
        }
        if(is.eof())
        {
            break;
        }
        
        
    }
    is.close();
    if(flag==0)
        cout<<"Record Not Found!!!"<<endl;
}


void admit::display()
{
    cout << "Email ID: " << getEmailID() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Gender: " << getGender() << endl;
    cout << "CNIC No: " << getCnic() << endl;
    cout << "Mobile No: " << getMobile() << endl;
    cout << "Date of birth: " << getDob() << endl;
    cout << "Symptoms: " << getSymptoms() << endl;
    cout << "Status: " << getStatus() << endl;
    cout << "Date of Admit: " << getDateOfAdmission() << endl;
    cout << "Date of Discharge: " << getDateOfDischarge() << endl;
    cout << "Precautions: " << getPrecautions() << endl;
    cout << "Medications: " << getMedications() << endl;
    cout << "Tests: " << getTests() << endl << endl;
}

void admit::readFromFile(ifstream &is)
{
    string s_temp;
    int i_temp;
    Date date_temp;
    double d_temp;
    char c;
    /*getline(is,s_temp, ',');
    setId(s_temp);*/
    getline(is,s_temp,',');    
    setName(s_temp);
    getline(is,s_temp,',');
    setAddress(s_temp);
    is>>i_temp>>c;
    setAge(i_temp);
    getline(is,s_temp,',');
    setGender(s_temp[0]);
    getline(is,s_temp,',');
    setCnic(s_temp);
    getline(is,s_temp,',');
    setMobile(s_temp);
    getline(is,s_temp, ',');
    setEmailID(s_temp);
    is>>date_temp>>c; 
    setDob(date_temp);
    getline(is,s_temp,',');
    setSymptoms(s_temp);
    getline(is,s_temp,',');
    setStatus(s_temp);
    is >> date_temp >> c;
    setDateOfAdmission(date_temp);
    is >> date_temp >> c;
    setDateOfDischarge(date_temp);
    getline(is,s_temp,',');
    setPrecautions(s_temp);
    getline(is,s_temp,',');
    setMedications(s_temp);
    getline(is,s_temp);
    setTests(s_temp);
}

void admit::writeInFile(ofstream &os)
{
    
    os<<getName()<<","<<getAddress()<<","<<getAge()<<","<<getGender()<<","<<getCnic()<<","<<getMobile()<<","<<getEmailID()<<","<<getDob()<<",";
    os<<getSymptoms()<<","<<getStatus()<<","<<getDateOfAdmission()<<","<<getDateOfDischarge()<<","<<getPrecautions()<<","<<getMedications()<<","<<getTests() << endl;

}