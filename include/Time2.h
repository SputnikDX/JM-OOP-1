#ifndef TIME2_H
#define TIME2_H


class Time2
{
    public:
        Time2();
        virtual ~Time2();
        int getHour();
        int getMinute();
        int getSecond();

    protected:

    private:
        int hour;
        int minute;
        int second;
};

#endif // TIME2_H
