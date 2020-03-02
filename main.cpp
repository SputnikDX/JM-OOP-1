#include <iostream>
#include "Date2.h"
#include "Time2.h"

using namespace std;

int main()
{
    /*try
    {
        Date2 myBD(19, 12, 1991); //(day/month/year)
        Date2 yourBD(9, 8, 2000);
        int result = yourBD - myBD;
        cout << result << endl;
        //cout << (++myBD).getDay() << "-" << myBD.getMonth() << "-" << myBD.getYear() << endl;
    }catch(const char * e) {
        cerr << e << endl;
    }
*/
    try
    {
    Time2 end(16,50,0); //hour, minute, second
    Time2 begin(16,0,0);
    end.printTime();
    begin.printTime();

    cout << end - begin << endl;
    }catch (const char * e) {
        cerr << e << endl;
    }

    return 0;
}

//Comments
/*    cout << "Enter your birthday > " << endl;
    cin >> myBD.setDay();
    cin >> myBD.setMonth();
    cin >> myBD.setYear();*/
