#ifndef class_Doctor
#define class_Doctor
#include "Person.h"
#include "Time.h"
#include <fstream>
class Doctor : public Person
{
    std::string type;
    std::string specialization;
    Time practiceStartHours;
    Time practiceEndHours;
    double fee;
    public:
    Doctor();

    Doctor(const Doctor &);

    std::string getType();
    void setType(std::string type);
    
    std::string getSpecialization();
    void setSpecialization(std::string specialization);

    Time getPracticeStartHours();
    void setPracticeStartHours(Time practiceStartHours);

    Time getPracticeEndHours();
    void setPracticeEndHours(Time practiceEndHours);

    double getFee();
    void setFee(double fee);

    void addDoctorData();
    void report();
    void displayDoctorData();
    void readFromFile(ifstream &is);
    
    bool writeInFile();
};
#endif
