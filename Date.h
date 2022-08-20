#ifndef CLASS_Date
#define CLASS_Date
#include <iostream>
using namespace std;
class Date
{
    int year;
    int month;
    int day;

    public:
    Date();
    Date(int d, int m, int y);

    void setDay(int n);
    void setMonth(int n);
    void setYear(int n);
    int getDay();
    int getMonth();
    int getYear();
    std::string getDate();
    friend istream & operator >> (istream &in,  Date &d); 
    friend ostream & operator << (ostream &out, const Date &d); 
};

#endif