#include "Doctor.h"
#include <iostream>
#include <string>
#include "globalFunctions.h"
#include <algorithm>

Doctor::Doctor(){
}

Doctor::Doctor(const Doctor & d):Person(d)
{
    fee=d.fee;
    practiceStartHours=d.practiceStartHours;
    practiceEndHours=d.practiceEndHours;
    specialization=d.specialization;
    type=d.type;
}

std::string Doctor::getSpecialization() {
    return this->specialization;
}
void Doctor::setSpecialization(std::string specialization) {
    this->specialization = specialization;
}

std::string Doctor::getType() {
    return this->type;
}
void Doctor::setType(std::string type) {
    this->type = type;
}

Time Doctor::getPracticeStartHours() {
    return this->practiceStartHours;
}
void Doctor::setPracticeStartHours(Time practiceStartHours) {
    this->practiceStartHours = practiceStartHours;
}

Time Doctor::getPracticeEndHours() {
    return this->practiceEndHours;
}
void Doctor::setPracticeEndHours(Time practiceEndHours) {
    this->practiceEndHours = practiceEndHours;
}

double Doctor::getFee() {
    return this->fee;
}
void Doctor::setFee(double fee) {
    this->fee = fee;
}

void Doctor::addDoctorData(){
        system("cls");
        string s_temp;
        int i_temp;
        char c_temp;
        Date d;
        Time t;
        cout<<"Please enter Doctor Details: "<<endl;

        cout<<"Enter name: ";
        cin.ignore();
        getline(cin,s_temp);    setName(s_temp);

        while(!is_valid_name(s_temp)){
        cout<<"Invalid Input. Please enter correct name: ";
        getline(cin,s_temp);    setName(s_temp);
        }

        cout<<"Enter Address: ";
        getline(cin,s_temp);    setAddress(s_temp);
        
        cout<<"Enter Age: "; 
        cin>>i_temp;    setAge(i_temp);
        
        cout<<"Enter Gender (Male=m / Female=f): ";
        cin>>c_temp;    setGender(c_temp);
        
        cin.ignore();
        cout<<"Enter CNIC Number (12101-*******-*): ";
        getline(cin,s_temp);    setCnic(s_temp);
        while(!is_valid_CNIC(s_temp)){
        cout<<"Invalid Input. Please enter correct CNIC number: ";
        getline(cin,s_temp);    setCnic(s_temp);
        }
        
        cout<<"Enter Mobile Number:(+923YZXXXXXXX) ";
        getline(cin,s_temp);    setMobile(s_temp);
        while(!is_valid_number(s_temp)){
        cout<<"Invalid Input. Please enter correct name: ";
        getline(cin,s_temp);    setMobile(s_temp);
        }

        cout<<"Enter date of birth (DD/MM/YYYY): ";
        cin>>d;     setDob(d);
        while(!is_valid_date(d)){
        cout<<"Invalid Input. Please enter correct name: ";
        cin>>d;    setDob(d);
        }

        cout<<"Enter Type  of Doctor (Physican/Surgeon): ";
        cin>>type;

        cout<<"Enter Doctor's Specialization: ";
        cin>>specialization;
        
        cout<<"Enter Doctor's Practice Start Hours (24 hour clock): ";
        cin>>t;     setPracticeStartHours(t);
        while(!is_valid_time(t)){
        cout<<"Invalid Input. Please enter correct starting time (24 hour clock): ";
        cin>>t;     setPracticeStartHours(t);
        }

        cout<<"Enter Doctor's Practice End Hours: ";
        cin>>t;     setPracticeEndHours(t);
        while(!is_valid_time(t)){
        cout<<"Invalid Input. Please enter correct ending time: ";
        cin>>t;     setPracticeEndHours(t);
        }

        cout<<"Enter Doctor's Fee : ";
        cin>>fee;
    }

    void Doctor::displayDoctorData(){
        cout << "Name: " << getName() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "Age: "<< getAge() << endl;
        cout << "Gender: " << getGender() << endl;
        cout << "CNIC No: " << getCnic() << endl;
        cout << "Mobile No: " << getMobile() << endl;
        cout << "Date of birth: " << getDob() << endl;
        cout << "Type(Surgeon / Physican):" << type <<endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Practice Start Hours: " << practiceStartHours << endl;
        cout << "Practice End Hours: " << practiceEndHours << endl;
        cout << "Fee: " << fee << endl;
    }
    void Doctor::report(){
        cout << "Name: " << getName();
        cout<<" Type: " << type;
        cout << " Specialization: " << specialization;
        cout << " Practice Start Hours: " << practiceStartHours;
        cout << " Practice End Hours: " << practiceEndHours;
        cout << " Fee: " << fee<<endl;
    }

    void Doctor::readFromFile(ifstream &is){
    string s_temp;
    int i_temp;
    Date date_temp;
    double d_temp;
    char c;
    Time t;
    getline(is,s_temp,',');     setName(s_temp);
    getline(is,s_temp,',');     setAddress(s_temp);
    is>>i_temp>>c;              setAge(i_temp);
    getline(is,s_temp,',');     setGender(s_temp[0]);
    getline(is,s_temp,',');     setCnic(s_temp);
    getline(is,s_temp,',');     setMobile(s_temp);
    is>>date_temp>>c;           setDob(date_temp);
    getline(is,s_temp,',');     setType(s_temp);  
    getline(is,s_temp,',');     setSpecialization(s_temp);
    is>>d_temp>>c;              setFee(d_temp); 
    is>>t>>c;                   setPracticeStartHours(t);
    is>>t;  getline(is,s_temp);                setPracticeEndHours(t); 
}


bool Doctor::writeInFile(){
    ofstream os;
    
    os.open("DoctorData.csv",ios::app);
    if(os.good()){
    os<<getName()<<","<<getAddress()<<","<<getAge()<<","<<getGender()<<","<<getCnic()<<","<<getMobile()<<","<<getDob()<<",";
    os<<getType()<<","<<getSpecialization()<<","<<getFee()<<","<<getPracticeStartHours()<<","<<getPracticeEndHours()<<endl;
    os.close();
    return true;
    }
    else
    {
        return false;
    }
    
}