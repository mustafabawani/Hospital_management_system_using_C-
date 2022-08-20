#include "Time.h"
#include <iomanip>
using namespace std;

void Time::setHour(int hour)
{
    this->hour=hour;
}
int Time::getHour()
{
    return this->hour;
}

void Time::setMinute(int minute)
{
    this->minute=minute;
}
int Time::getMinute()
{
    return this->minute;
}

string Time::getTime()
{
    return to_string(this->hour) + ":" + to_string(this->minute);
}

bool Time::operator < (const Time& T) const{
    return((hour<=T.hour) && (minute<T.minute));
}
bool Time::operator > (const Time& T) const{
    return((hour>=T.hour) && (minute>T.minute));
}

istream & operator >> (istream &in,  Time &t) 
{ 
    
    in >> t.hour;
    in.get();
    in >> t.minute;
    return in;
} 


ostream & operator << (ostream &out, const Time &t) 
{ 
    out << setw(2) << setfill('0') << t.hour;
    out << ":"  << setw(2) << setfill('0') <<t.minute;
    return out; 
}
