#include "Time2.h"
#include <iostream>
#include <iomanip>

Time2::Time2(int h, int m, int s)
{
    try{
        setHour(h).setMinute(m).setSecond(s);
    }catch(const char * e){
        throw e;
    }
    //ctor
}

Time2::~Time2()
{
    //dtor
}

int Time2::getHour()
{
    if (period == "AM")
    {
        if (hour == 0)
            return 12;
        else
            return hour;
    }
    else
    {
        if (hour == 0 || hour == 12)
            return 12;
        else
            return (hour-12);
    }

}

int Time2::getMinute()
{
    return minute;
}
int Time2::getSecond()
{
    return second;
}
string Time2::getPeriod()
{
    return period;
}

Time2& Time2::setHour(int h)
{
    if (h >= 0 && h <= 11)
    {
        hour = h;
        period = "AM";
        return *this;
    }
    else if (h >= 12 && h <= 23)
    {
        hour = h;
        period = "PM";
        return *this;
    }
    else
    {
        throw "Invalid Hour";
    }
}

Time2& Time2::setMinute(int m)
{
    if (m >= 0 && m <= 59)
    {
        minute = m;
        return *this;
    }
    else
    {
        throw "Invalid Minute";
    }
}
Time2& Time2::setSecond(int s)
{
    if (s >= 0 && s <= 59)
    {
        second = s;
        return *this;
    }
    else
    {
        throw "Invalid Second";
    }
}

bool Time2::operator == (Time2 rhs)
{
    if (getHour() == rhs.getHour() && minute == rhs.getMinute() && second == rhs.getSecond())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Time2::operator != (Time2 rhs)
{
    return !(*this == rhs);
}

Time2& Time2::operator ++ ()
{
    second++;
    if (second == 60)
    {
        second = 00;
        minute++;
        if (minute == 60)
        {
            minute = 0;
            hour++;
            if (hour == 24)
            {
                setHour(0);
            }
            else
                setHour(hour);
        }
    }
    return *this;
}

Time2 Time2::operator ++ (int p)
{
    Time2 tmp = *this;
    ++(*this);
    return tmp;
}

Time2& Time2::operator + (int p)
{
    //eg: 12:59:30 + 130
    second += p; // 30 + 130 = 160
    int loop = 0;
    while (second >= 60)
    {
        loop++;
        second -= 60; //second = 100; 40
        minute++; // 60; 1
        if (minute == 60)
        {
            minute = 0;
            hour ++; //hour = 13
            if (hour == 24)
            {
                setHour(0);
            }
            else
                setHour(hour);
        }
    }
    cout << loop << endl;
    return *this;
}

Time2& Time2::operator -- ()
{
    second--;
    if(second < 0)
    {
        second = 59;
        minute--;
        if (minute < 0)
        {
            minute = 59;
            hour--;
            if (hour < 0)
            {
                setHour(23);
            }
            else
                setHour(hour);
        }
    }
    return *this;
}

Time2 Time2::operator -- (int s)
{
    Time2 tmp = *this;
    --(*this);
    return tmp;
}
Time2& Time2::operator - (int s)
{
    //eg: 12:00:01 - 121 seconds
    while (s >= 60 && second < s) //s = 121
    {
        s -= 60; // s = 61; s = 1
        minute--;
        if (minute < 0)
        {
            minute = 59;
            hour--;
            if (hour < 0)
            {
                setHour(23);
            }
            else
                setHour(hour);
        }
    }
    second -= s;
    if (second < 0)
    {
        minute--;
        if (minute < 0)
        {
            minute = 59;
            hour--;
            if (hour < 0)
            {
                setHour(23);
            }
            else
                setHour(hour);
        }
        second += 60;
    }
    return *this;
}

Time2& Time2::addSecond(int p)
{
    *this + p;
    return *this;
}

Time2& Time2::addMinute(int p)
{
    p *= 60;
    *this + p;
    return *this;
}

Time2& Time2::addHour(int p)
{
    p *= 60*60;
    *this + p;
    return *this;
}

Time2& Time2::subSecond(int s)
{
    *this - s;
    return *this;
}

Time2& Time2::subMinute(int s)
{
    s *= 60;
    *this - s;
    return *this;
}

Time2& Time2::subHour(int s)
{
    s *= 60*60;
    *this - s;
    return *this;
}

int Time2::operator - (Time2 secTime)
{
    int timeDiff = 0;
    Time2 compTime = *this;
    while (compTime != secTime)
    {
        compTime--;
        timeDiff++;
    }
    return timeDiff;
}

Time2& Time2::printTime()
{
    cout << getHour() << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << " " << period << endl;
    return *this;
}
