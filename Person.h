#ifndef CLASS_Person
#define CLASS_Person
#include <iostream>
#include "Date.h"

class Person
{
    std::string name;
    int age;
    std::string address;
    char gender;
    std::string cnic;
    std::string mobile;
    Date dob;

    public:

    std::string getName();
    void setName(std::string name); 

    std::string getAddress();
    void setAddress(std::string address); 

    int getAge(); 
    void setAge(int age); 


    char getGender(); 
    void setGender(char gender); 


    std::string getCnic(); 
    void setCnic(std::string cnic);


    std::string getMobile(); 
    void setMobile(std::string mobile);


    Date getDob();
    void setDob(Date dob);



    

};

#endif
