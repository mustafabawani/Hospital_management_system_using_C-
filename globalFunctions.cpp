#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <stdlib.h>
#include <algorithm>
#include <conio.h>
#include "Date.h"
#include "Doctor.h"
#include "Patient.h"
#include "admit.h"
#include "checkup.h"
#include "Admin.h"
#include "Accountant.h"
#include "Time.h"
#include "user.h"

#include "globalFunctions.h"
using namespace std;

Doctor *doc;
admit *adm;
checkup *check;
Admin *admin;
User *user;
Accountant *acc;

int choice;

string getHiddenPass()
{
	string pass = "";
   	char ch;
	ch = _getch();
	while(ch != 13){//character 13 is enter
		if(ch == 8 && pass.size() == 0)
		{
			//do nothing
		}
		else if(ch == 8)
		{
			cout << "\b \b";
			pass.pop_back();
		}
		else
		{
			pass.push_back(ch);
			cout << '*';
		}
		ch = _getch();
		
	}
	return pass;
}

void loading(){
	system("cls");
	cout<<"\nPlease wait while we are processing \n L.......";
	Sleep(100);
	system("cls");
	cout<<"\nPlease wait while we are processing \n LO.......";
	Sleep(100);
	system("cls");
	cout<<"\nPlease wait while we are processing \n LOA.......";
	Sleep(100);
	system("cls");
	cout<<"\nPlease wait while we are processing \n LOAD.......";
	Sleep(100);
	system("cls");
	cout<<"\nPlease wait while we are processing \n LOADI.......";
	Sleep(100);
	system("cls");
	cout<<"\nPlease wait while we are processing \n LOADIN.......";
	Sleep(100);
	system("cls");
	cout<<"\nPlease wait while we are processing \n LOADING.......";
	Sleep(100);
	system("cls");
}

void welcome(){
		cout << "\n\n\n\t\t\t********************************\t\t\t\n";
		cout << "\t\t\tWelcome TO GIGA National Hospital\t\t\t\n";
		cout << "\t\t\t********************************\t\t\t\n\n\n";
}


void deleteEmptyLinesFromDoctorFile(){
    ifstream in("DoctorData.csv");
    string line, text;
    getline(in, line);
        if (!(line.empty() || line.find_first_not_of(' ') == string::npos))
            text +=  line;
    
    while (!in.eof()){
        getline(in, line);
        if (!(line.empty() || line.find_first_not_of(' ') == string::npos))
            text +=  "\n" + line ;
    }
    in.close();
    ofstream out("DoctorData.csv");
    out << text;
}

void mainInterface()
{
    system("cls");
    welcome();
	cout << "1. Login" << endl;
    cout << "2. Covid-19 Testing Service" << endl << endl;
	cout << "0. Exit" << endl << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	switch(choice)
	{
		case 1:
			login();
			break;
		case 2:
            user = new User;
            user->testCorona();
            delete user;
            break;
        case 0:
			exit(0);
		default:
			cout << "Invalid Choice!!" << endl;
			Sleep(2000);
			break;
	}
	mainInterface();
    
}

void login()
{
	system("cls");
	welcome();
	string id, pass;
	cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Password: ";
    pass = getHiddenPass();
    admin = new Admin;
    if (id == admin->getID() && pass == admin->getPass())
    {
        adminInterface();
    }
    else
    {
        bool verified = verifyPatient(id, pass);
        if(verified)
        {
            userPatientInterface(id, pass);
        }
        else
        {
            cout << "Invalid ID or Password!!";
            Sleep(1500);
        }
        
    }
}

void adminInterface()
{
	loading();
    system("CLS");
    cout << "1. Patients" << endl;
    cout << "2. Doctors" << endl << endl;
    cout << "0. Log out" << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice)
    {
        case 1:
            adminPatientInterface();
            break;
        case 2:
            adminDoctorInterface();
            break;
        case 0:
            delete admin;
            mainInterface();
        default:
            cout << "Invalid Choice!!" << endl;
            Sleep(2000);
    }
    adminInterface();

}

void adminPatientInterface()
{
	loading();
    system("CLS");
    cout << "Select Patient Type: " << endl << endl;
    cout << "1. Admit Patients" << endl;
    cout << "2. Checkup Patients" << endl;
    cout << "0. Back" << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;

	switch(choice)
    {
        case 1:
        {
            adminAdmitPatientInterface();
			break;
        }
        case 2:
        {	
			adminCheckupPatientInterface();
			break;
        }
        case 0:
            return;
        default:
            cout << "Invalid Choice!!";
            Sleep(2000);

    }
    adminPatientInterface();

}

void adminAdmitPatientInterface()
{
    system("cls");
    cout << "1. Add Patient" << endl;
    cout << "2. Update Patient Data" << endl;
    cout << "3. Search for Patient" << endl;
    cout << "4. Bill Patient" << endl << endl;
    cout << "0. Back" << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;

	switch(choice)
    {
        case 1:
        {
            admin->addAdmitPatientData();
			break;
        }
        case 2:
        {	
			admin->updateAdmitPatientData();
			break;
        }
        case 3:
            admin->searchAdmitPatient();
            break;
        case 4:
            admin->billAdmitPatient();
			break;
        case 0:
            return;
        default:
            cout << "Invalid Choice!!";
            Sleep(2000);

    }
    adminAdmitPatientInterface();
}

void adminCheckupPatientInterface()
{
    system("cls");
    cout << "1. Add Patient" << endl;
    cout << "2. Update Patient Data" << endl;
    cout << "3. Search for Patient" << endl;
    cout << "4. Bill Patient" << endl << endl;
    cout << "0. Back" << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;

	switch(choice)
    {
        case 1:
        {
            admin->addCheckupPatientData();
			break;
        }
        case 2:
        {	
			admin->updateCheckupPatientData();
			break;
        }
        case 3:
            admin->searchCheckupPatient();
            break;
        case 4:
			admin->billCheckupPatient();
        case 0:
            return;
        default:
            cout << "Invalid Choice!!";
            Sleep(2000);

    }
    adminCheckupPatientInterface();
}
bool verifyPatient(string id, string pass)
{
    ifstream is("patientlogin(encrypted).csv");
    string tempID, tempPass;
    int flag = 0;
    getline(is, tempID, ',');
    getline(is, tempPass);
    while(tempID != id || decrypt(tempPass) != pass)
    {
        if(is.eof())
        {
            flag = 1;
            break;
        } 
        getline(is, tempID, ',');
        getline(is, tempPass);
    }
    if(flag == 0)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

string encrypt(string str)
{
    int i;
    for(i = 0; str[i] != '\0'; i++)
        str[i] = str[i] + 2; //the key for encryption is 2 that is added to ASCII value

    return str;
}

string decrypt(string str)
{
    int i;
    for(i = 0; str[i] != '\0'; i++)
        str[i] = str[i] - 2; //the key for encryption is 2 that is subtracted to ASCII value

    return str;
}

bool is_valid_name(const std::string& s)
{
    for (const char c : s) {
        if (!isalpha(c) && !isspace(c))
            return false;
    }

    return true;
}

bool is_valid_CNIC(const string& cnic){
    static const string AllowedChars = "0123456789";
    int i=0;
    for(auto cnicChar = cnic.begin() ; cnicChar !=cnic.end() ; ++cnicChar , ++i){
        if(i==5 || i==13)
        continue;
        if(AllowedChars.end() == std::find(AllowedChars.begin(), AllowedChars.end(), *cnicChar))
        {
            return false;
        }
    }
    return true;
}
bool is_valid_email(const std::string& str)
{
    // Locate '@'
    auto at = std::find(str.begin(), str.end(), '@');
    // Locate '.' after '@'
    auto dot = std::find(at, str.end(), '.');
    // make sure both characters are present
    return (at != str.end()) && (dot != str.end());
}

bool is_valid_number(const std::string& number)
{
    static const std::string AllowedChars = "0123456789";
    if(number[0]!='+')
        return false;
    
    for(auto numberChar = number.begin()+1 ; numberChar != number.end() ; ++numberChar)

        if(AllowedChars.end() == std::find(AllowedChars.begin(), AllowedChars.end(), *numberChar))
        {
            return false;
        }

    return true;
}

bool is_valid_date(Date d){
if(d.getYear()>1900 && d.getYear()<2021)
       {
        if(d.getMonth()==1 || d.getMonth()==3 || d.getMonth()==5|| d.getMonth()==7|| d.getMonth()==8|| d.getMonth()==10 ||d.getMonth()==12 && d.getDay()>0 && d.getDay()<=31)
         return true;
        if(d.getMonth()==4 || d.getMonth()==6 || d.getMonth()==9|| d.getMonth()==11 && d.getDay()>0 && d.getDay()<=30)
            return true;
        if(d.getMonth()==2){
            if((d.getYear()%400==0 || (d.getYear()%100!=0 && d.getYear()%4==0)) && d.getDay()>0 && d.getDay()<=29)
                return true;
            if(d.getDay()>0 && d.getDay()<=28)
                return true;
               }
       }
       return false;
}

bool is_valid_time(Time t){
    if(t.getHour()>=0 && t.getHour()<24){
        if(t.getMinute()>=00 && t.getMinute()<60)
         return true;
    }
    return false;
}

bool is_valid_ward(string room){
    if(room=="private" || room=="semi private" || room=="general")
        return true;
    
    return false;
}

void userPatientInterface(string id, string pass)
{
    user = new User;
    user->setID(id);
    user->setPassword(pass);
    loading();
    system("cls");
    cout << "1. Book an Appointment" << endl;
    cout << "2. Show Patient Details" << endl;
    cout << "3. Show Billing Details" << endl;
    cout << "4. Display All Doctors" << endl;
    cout << "5. Display Hospital Details" << endl << endl;
    cout << "0. Back" << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice)
    {
        case 1:
            user->appoitment();
            break;
        case 2:
            user->showPatientDetails(id);
            break;
        case 3:
            user->showBillingDetails(id);
            break;
        case 4:
            user->displayAllDoctor();
            break;
        case 5:
            user->displayHospitalDetails();
            break;
        case 0:
            return;
        default:
            cout << "Invalid Choice!!";
            Sleep(2000);
    }
    delete user;
    userPatientInterface(id, pass);

}
void adminDoctorInterface()
{
    system("cls");
    cout << "1. Add Doctor" << endl;
    cout << "2. Update Doctor Data" << endl;
    cout << "3. Delete Doctor" << endl;
    cout << "4. Search Doctor" << endl;
    cout << "5. Display all Doctors" << endl << endl;
    cout << "0. Back" << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice)
    {
        case 1:
            admin->addDoctorData();
            break;
        case 2:
            admin->updateDoctorData();
            break;
        case 3:
            admin->deleteDoctorData();
            break;
        case 4:
            admin->searchDoctorData();
            break;
        case 5:
            admin->displayAllDoctor();
            break;
        case 0:
            return;
        default:
            cout << "Invalid Choice!!";
            Sleep(2000);
    }
    adminDoctorInterface();

}






