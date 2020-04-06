#ifndef DATE2_H
#define DATE2_H

using namespace std;

class Date2
{
    friend void printShort(Date2);
    friend ostream& operator << (ostream&, const Date2);

    public:
        Date2(int, int, int);
        virtual ~Date2();
        int getDay();
        int getMonth();
        int getYear();
        Date2& setAll(int, int, int);
        Date2& setDayPub(int);
        Date2& setMonthPub(int);
        Date2& setYearPub(int);
        Date2& Y2K();
        bool operator == (Date2);
        bool operator != (Date2);
        Date2& operator ++ (); //prefix ++
        Date2 operator ++ (int); //postfix ++
        Date2& operator -- (); //prefix --
        Date2 operator -- (int); //postfix --
        Date2& operator + (unsigned int);
        Date2& operator += (unsigned int);
        Date2& operator - (unsigned int);
        int operator - (Date2);
        Date2& printDate();

    protected:

    private:
        int day;
        int month;
        int year;
        void setDay(int);
        void setMonth(int);
        void setYear(int);
        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30, 31};
        string monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

};

#endif // DATE2_H
