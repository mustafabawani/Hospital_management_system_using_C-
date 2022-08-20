#include "Date.h"
#include <string.h>
#include <iostream>

using namespace std;

Date::Date() {}
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

void Date::setDay(int n)
{
    this->day = n;
}
void Date::setMonth(int n)
{
    this->month = n;
}
void Date::setYear(int n)
{
    this->year = n;
}
int Date::getDay()
{
    return this->day;
}
int Date::getMonth()
{
    return this->month;
}
int Date::getYear()
{
    return this->year;
}
std::string Date::getDate()
{
    return to_string(this->day) + "/" + to_string(this->month) + "/" + std::to_string(this->year);
}

istream & operator >> (istream &in,  Date &d) 
{ 
    
    in >> d.day;
    in.get();
    in >> d.month;
    in.get();
    in >> d.year;
    return in;
} 
ostream & operator << (ostream &out, const Date &d) 
{ 
    out << d.day;
    out << "/" << d.month;
    out << "/" << d.year;

    return out; 
} 