#include"checkup.h"
#include "globalFunctions.h"
#include <Windows.h>
#include <string>
#include<iostream>
using namespace std;

checkup::checkup(){

}

checkup::checkup(string symptoms)
{
    setSymptoms(symptoms);
}

checkup::checkup(const checkup & c):Patient(c)
{
    dateOfCheckup=c.dateOfCheckup;
}

void checkup::setDateOfCheckup(Date dateOfCheckup)
{
    this->dateOfCheckup=dateOfCheckup;
}

Date checkup::getDateOfCheckup()
{
    return dateOfCheckup;
}

void checkup::addCheckupPatient()
{
    int user_age;
    char ch;
    string user;
    system("cls");
    Date d;
    cout << "Please Enter Patient Details" << endl;
    cout<<"Enter name: ";
    cin.ignore();
    getline(cin,user);    
    setName(user);

    while(!is_valid_name(user))
    {
        cout<<"Invalid Input. Please enter correct name: ";
        getline(cin,user);    
        setName(user);
    }

    cout << "Enter Address: ";
    getline(cin,user);
    setAddress(user);
    cout<<"Enter Age: ";
    cin>>user_age;
    cin.ignore();
    setAge(user_age);
    cout<<"Enter Gender: ";
    cin >> ch;
    setGender(ch);
    cin.ignore();
    
    cout<<"Enter CNIC Number (12101-*******-*): ";
    getline(cin,user);    
    setCnic(user);

    while(!is_valid_CNIC(user))
    {
        cout<<"Invalid Input. Please enter correct CNIC number: ";
        getline(cin,user);    
        setCnic(user);
    }

    cout<<"Enter Mobile Number:(+923YZXXXXXXX): ";
    getline(cin,user);    
    setMobile(user);
    while(!is_valid_number(user))
    {
        cout<<"Invalid Input. Please enter correct Mobile Number: ";
        getline(cin,user);    
        setMobile(user);
    }

    cout<<"Enter Email ID: ";
    getline(cin,user);
    setEmailID(user);
    cout<<"Enter date of birth (DD/MM/YYYY): ";
    cin>>d;     
    setDob(d);
        
    while(!is_valid_date(d))
    {
        cout<<"Invalid Input. Please enter correct date of birth (DD/MM/YYYY): ";
        cin>>d;    
        setDob(d);
    }

    cin.ignore();
    cout << "Enter Symptoms: ";
    getline(cin,user);
    replace(user.begin(), user.end(), ',', '|');
    setSymptoms(user);
}

void checkup::updateCheckupPatient(string user , string update)
{
    int flag=0;
    transform(update.begin(), update.end(), update.begin(), ::tolower);
    checkup temp;
    ofstream os ("tempData.csv");
    ifstream is ("checkupData.csv");
    temp.readFromFile(is);
    while(is)
    {
        if(temp.getName()==user  )
        {
            string new_data;
            cout << "Enter " << update << " to update" << endl;
            getline(cin,new_data);
            replace(user.begin(), user.end(), ',', '|');
            if(update=="name")
            {
                temp.setName(new_data);
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
            flag=1;
        }
        temp.writeInFile(os);
        temp.readFromFile(is);
    }
    is.close();
    os.close();
    remove("checkupData.csv");
    rename("tempData.csv","checkupData.csv");
    if(flag==0)
        cout<<"Record Not Found!!!"<<endl;
    else
        cout << "Record updated successfully!!!" << endl;
    Sleep(1000);

}

void checkup::SearchCheckupPatient(string user)
{
    int flag=0;
    checkup temp;
    ifstream is ("checkupData.csv");
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


void checkup::display()
{
    cout << "Email ID: " << getEmailID() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Gender: " << getGender() << endl;
    cout << "CNIC No: " << getCnic() << endl;
    cout << "Mobile No: " << getMobile() << endl;
    cout << "Date of birth: " << getDob() << endl;
    cout << "Symptoms: " << getSymptoms() << endl;
    cout << "Precautions: " << getPrecautions() << endl;
    cout << "Medications: " << getMedications() << endl;
    
}

void checkup::readFromFile(ifstream &is)
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
    setPrecautions(s_temp); 
    getline(is,s_temp);
    setMedications(s_temp); 
}

void checkup::writeInFile(ofstream &os)
{
    os<<getName()<<","<<getAddress()<<","<<getAge()<<","<<getGender()<<","<<getCnic()<<","<<getMobile()<<","<<getEmailID()<<","<<getDob()<<",";
    os<<getSymptoms()<<","<<getPrecautions()<<","<<getMedications()<< endl ;
}