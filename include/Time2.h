#ifndef TIME2_H
#define TIME2_H
#include <iostream>

using namespace std;


class Time2
{
    public:
        Time2(int, int, int);
        virtual ~Time2();
        int getHour();
        int getMinute();
        int getSecond();
        string getPeriod();
        Time2& setHour(int);
        Time2& setMinute(int);
        Time2& setSecond(int);
        Time2& addSecond(int);
        Time2& addMinute(int);
        Time2& addHour(int);
        Time2& subSecond(int);
        Time2& subMinute(int);
        Time2& subHour(int);

        bool operator == (Time2);
        bool operator != (Time2);
        Time2& operator ++ ();
        Time2 operator ++ (int);
        Time2& operator + (int);
        Time2& operator -- ();
        Time2 operator -- (int);
        Time2& operator - (int);
        int operator - (Time2);
        Time2& printTime();

    protected:

    private:
        int hour;
        int minute;
        int second;
        string period;
};

#endif // TIME2_H
