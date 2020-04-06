#include <iostream>
#include "Date2.h"

using namespace std;

Date2::Date2(int d, int m, int y)
{
    try {
        setAll(d, m, y);
    }catch(const * e){
        throw e;
    }
    //ctor
}

Date2::~Date2()
{
    //cout << "Deconstructor runs" << endl;
    //dtor
}

int Date2::getDay()
{
    return day;
}

int Date2::getMonth()
{
    return month;
}

int Date2::getYear()
{
    return year;
}

void Date2::setDay(int d)
{
    /*
    if(year % 4 == 0 && month == 2)
        leapAdj = 1;
    else
        leapAdj = 0;
    //The above code is functionally the same as below.
    */

    int leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0;

    if(d >= 1 && d <= daysInMonth[month-1] + leapAdj)
    {
        day = d;
    }else{
        throw "Invalid day.";
    }

}

void Date2::setMonth(int m)
{
    if (m >= 1 && m <= 12)
    {
        month = m;
    }
    else
    {
        throw "Invalid month.";
    }
}

void Date2::setYear(int y)
{
    if(month == 2 && day == 29 && y % 4 != 0)
        throw "Invalid Year.";
    else
        year = y;
}

Date2& Date2::setAll(int d, int m, int y)
{
    try{
        setYear(y);
        setMonth(m);
        setDay(d);
        return *this;
    }catch(const char * e){
        throw e;
    }
}

Date2& Date2::setDayPub(int d)
{
    setDay(d);
    return *this;
}

Date2& Date2::setMonthPub(int m)
{
    int leapAdj = (year % 4 == 0 && m == 2) ? 1 : 0;
    if (m >= 1 && m <= 12 && day <= (daysInMonth[m-1] + leapAdj))
    {
        month = m;
        return *this;
    }
    else
    {
        throw "Invalid month.";
    }
}

Date2& Date2::setYearPub(int y)
{
    setYear(y);
    return *this;
}

bool Date2::operator == (Date2 rhs)
{
    if(day == rhs.getDay() && month == rhs.getMonth() && year == rhs.getYear())
        return true;
    else
        return false;
}

bool Date2::operator != (Date2 rhs)
{
    return !(*this == rhs);
}

Date2& Date2::operator ++ ()
{
    int leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0;
    ++day;
    if(day > daysInMonth[month-1] + leapAdj)
    {
        ++month;
        day = 1;
        if(month > 12)
        {
            ++year;
            month = 1;
        }
    }
    return *this;
}

Date2 Date2::operator ++ (int)
{
    Date2 tmp = *this;
    ++(*this);
    return tmp;
}

Date2& Date2::operator -- ()
{

    if(month == 1 && day == 1){
        day = 31;
        month = 12;
        year--;
    }else if(day == 1){
        month--;
        int leapAdj = (year%4 == 0 && month == 2 ) ? 1 : 0;
        day = daysInMonth[month-1] + leapAdj;
    }else{
        day--;
    }
    return *this;
}

Date2 Date2::operator -- (int)
{
    Date2 tmp = *this;
    --(*this);
    return tmp;
}

Date2& Date2::operator + (unsigned int p)
{

    //eg: Dec 1st 2004 + 60 days
    int leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0;
    day += p; //day = 61
    if(day < daysInMonth[month-1] + leapAdj) //False; daysInMonth[11]=31 day = 61
    {
        return *this;
    }
    else //True
    {
        while(day > daysInMonth[month-1] + leapAdj || month > 12) //Start loop;
        {
            if(month > 12) //False; True;
            {
                year++; //Year = 2005
                month = 1;
            }
            else //True;
            {
                day -= (daysInMonth[month-1] + leapAdj); //Day(61) -= daysInMonth (31) = 30
                month++; //month = 13
                leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0; //0;
                // Loop 1: Day = 30, month = 13;
            }
        }
        return *this;
    }
}

Date2& Date2::operator - (unsigned int s) //Loops tracked in comments. Semicolons separate each loop.
{
    //eg: March 15th, 2004 - 60 days
    int leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0;
    while (s > 0 && day < s)
    {
        s -= day; // 60 - 15 = 45; 45 - 29 = 16
        month--; // Feb; Jan
        if (month == 0)
        {
            month = 12;
            day = 31;
            year--;
        }
        leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0; //1;0
        day = (daysInMonth[month-1] + leapAdj); // day = 29; day = 31
    }
    day -= s; // 31 - 16 = 15
    return *this; // Jan 15th, 2004
}

int Date2::operator - (Date2 secDate)
{
    //I tried to do this the right way and it was insane. This runtime is terrible but my sanity is more important than processing time.
    int dayDiff = 0;
    Date2 compDate = *this;
    while (compDate != secDate) //Runtime: O(n) isn't that bad I guess.
    {
        compDate--;
        dayDiff++;
    }
    return dayDiff;
}

Date2& Date2::printDate()
{
    //cout << day << "/" << month << "/" << year << " //(day/month/year)" << endl;
    if (day == 1)
        cout << monthNames[month-1] << " " << day << "st, " << year << endl;
    else if (day == 2)
        cout << monthNames[month-1] << " " << day << "nd, " << year << endl;
    else if (day == 3)
        cout << monthNames[month-1] << " " << day << "rd, " << year << endl;
    else
        cout << monthNames[month-1] << " " << day << "th, " << year << endl;
    return *this;
}

Date2& Date2::operator += (unsigned int p)
{
    *this = *this + p;
    return *this;
}

void printShort(Date2 aDate) //this is a friend function so no scope resolution.
{
     if (aDate.day == 1)
        cout << aDate.monthNames[aDate.month-1] << " " << aDate.day << "st, " << aDate.year << endl;
    else if (aDate.day == 2)
        cout << aDate.monthNames[aDate.month-1] << " " << aDate.day << "nd, " << aDate.year << endl;
    else if (aDate.day == 3)
        cout << aDate.monthNames[aDate.month-1] << " " << aDate.day << "rd, " << aDate.year << endl;
    else
        cout << aDate.monthNames[aDate.month-1] << " " << aDate.day << "th, " << aDate.year << endl;
}

ostream& operator << (ostream& output, const Date2 aDate)
{
    output << aDate.month << "-" << aDate.day << "-" << aDate.year << endl;
    return output;
}
