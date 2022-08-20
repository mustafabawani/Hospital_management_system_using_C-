#ifndef class_Time
#define class_Time

#include <string.h>
#include <iostream>

using namespace std;

class Time
{
    //protected:
    int hour,minute;
    public:
    void setHour(int hour);
    int getHour();

    void setMinute(int minute);
    int getMinute();

    string getTime();
    
    bool operator <(const Time& T) const;
    bool operator >(const Time& T) const;
    
    friend istream & operator >> (istream &in,  Time &t);
    friend ostream & operator << (ostream &out, const Time &t);
    
};
#endif
