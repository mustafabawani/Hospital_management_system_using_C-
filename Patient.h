#ifndef class_Patient
#define class_Patient
#include "Person.h"
#include "Date.h"
#include <iostream>

class Patient : public Person
{
    std::string emailID;
    std::string pass;
    std::string symptoms;
    std::string precautions;
    std::string medications;
    Person details;


    public:



    std::string getEmailID();
    void setEmailID(std::string id);

    std::string getPass();
    void setPass(std::string pass);

    Person getDetails();
    void setDetails(Person dob);

    std::string getSymptoms();
    void setSymptoms(std::string symptoms);


    std::string getPrecautions();
    void setPrecautions(std::string precautions);


    std::string getMedications();
    void setMedications(std::string medications);

    void generatePassword();


    virtual void display()=0;

};

#endif
