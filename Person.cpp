#include "Person.h"

std::string Person::getName() {
    return this->name;
}
void Person::setName(std::string name) {
    this->name = name;
}

std::string Person::getAddress(){
    return this->address;
}
void Person::setAddress(std::string address){
    this->address=address;
}

int Person::getAge() {
    return this->age;
}
void Person::setAge(int age) {
    this->age = age;
}


char Person::getGender() {
    return this->gender;
}
void Person::setGender(char gender) {
    this->gender = gender;
}


std::string Person::getCnic() {
    return this->cnic;
}
void Person::setCnic(std::string cnic) {
    this->cnic = cnic;
}


std::string Person::getMobile() {
    return this->mobile;
}
void Person::setMobile(std::string mobile) {
    this->mobile = mobile;
}


Date Person::getDob() {
    return this->dob;
}
void Person::setDob(Date dob) {
    this->dob = dob;
}