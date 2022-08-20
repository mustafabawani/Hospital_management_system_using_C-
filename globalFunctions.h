#ifndef GLOBALFUNCTION_H
#define GLOBALFUNCTION_H

#include <iostream>
#include "Doctor.h"
#include "admit.h"
#include "checkup.h"
#include "Admin.h"
#include "Accountant.h"
#include "Time.h"
#include "user.h"

extern Doctor *doc;
extern admit *adm;
extern checkup *check;
extern Admin *admin;
extern User *user;
extern Accountant *acc;

void login();
std::string getHiddenPass();
void loading();
void welcome();
void deleteEmptyLinesFromDoctorFile();
void mainInterface();
void adminInterface();
void adminPatientInterface();
void adminAdmitPatientInterface();
void adminCheckupPatientInterface();
bool verifyPatient(std::string id, std::string pass);
std::string encrypt(std::string str);
std::string decrypt(std::string str);
void adminDoctorInterface();
void userPatientInterface(std::string id, std::string pass);
bool is_valid_name(const std::string& s);
bool is_valid_CNIC(const string& cnic);
bool is_valid_email(const std::string& str);
bool is_valid_number(const std::string& number);
bool is_valid_date(Date d);
bool is_valid_time(Time t);
bool is_valid_ward(string room);
#endif