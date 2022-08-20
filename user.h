#ifndef CLASS_User
#define CLASS_User
#include <string>
using namespace std;
class User
{
    string ID;
    string password;

    public:
    void setID(std::string id);
    std::string getID();
    void setPassword(std::string pass);
    std::string getPassword();
    void appoitment();
    void displayAllDoctor();
    void testCorona();
    void displayHospitalDetails();
    void showPatientDetails(std::string id);
    void showBillingDetails(std::string id);
};
#endif