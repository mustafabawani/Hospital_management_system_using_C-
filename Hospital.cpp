#include "Hospital.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


void Hospital::displayAllCoronaHospital(){
    ifstream is("CoronaHospital.csv");
    string capacity;
    while(!is.eof()){
        getline(is,name,',');
        getline(is,phoneNumber,',');
        getline(is,location,',');
        getline(is,capacity);
    
        cout<<"Name: "<<name<<" Phone Number: "<<phoneNumber;
        cout<< " Location: "<<location<<" Testing Capacity/ Day: "<<capacity<<endl;
    
    }
    
    is.close();
}

void Hospital::displayGIGAHospital(){
    ifstream is("MyHospital.csv");
        getline(is,name,',');
        getline(is,phoneNumber,',');
        getline(is,location);
        cout<<"Name: "<<name<<" Phone Number: "<<phoneNumber<< " Location: "<<location<<endl;
    is.close();
}