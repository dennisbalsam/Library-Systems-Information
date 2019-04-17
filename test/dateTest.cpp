#include <iostream>
#include "../Date.h"

using namespace std;

enum DATE {MONTH, DAY, YEAR};

int main()
{
    // general date constructor
    Date d(3,10,2020);

    // test setters and getters
    int dateDesired[] = {5, 22, 2025};

    cout << "Date desired:" << endl;
    for(auto i : dateDesired)
        cout << i << " ";
    cout << endl;
    cout << endl;

    // testing getters
    cout << "testing getters:" << endl;
    cout << "Current date:" << endl;
    cout << d.getDay() << " ";
    cout << d.getMonth() << " ";
    cout << d.getYear() << endl;
    cout << endl;
    

    // testing setters
    cout << "testing setters:" << endl;

    cout << "setDay(dateDesired[DAY])" << endl;
        d.setDay(dateDesired[DAY]);
    cout << "setMonth(dateDesired[MONTH])" << endl;
        d.setMonth(dateDesired[MONTH]);
    cout << "setYear(dateDesired[YEAR])" << endl;
        d.setYear(dateDesired[YEAR]);

    cout << endl;

    // testing getters again
    cout << "testing getters again:" << endl;
    cout << "New current date:" << endl;
    cout << d.getMonth() << " ";
    cout << d.getDay() << " ";
    cout << d.getYear() << endl;
    cout << endl;


    cout << "Testing setter setDate(m, d, y): \n\tIncrementing month day and year by 1." << endl;
    cout << "d.setDate(dateDesired[MONTH]+1, dateDesired[DAY]+1, dateDesired[YEAR]+1)" << endl;
    d.setDate(dateDesired[MONTH]+1, dateDesired[DAY]+1, dateDesired[YEAR]+1);
    cout << "New current date:" << endl;
    cout << d.getMonth() << " ";
    cout << d.getDay() << " ";
    cout << d.getYear() << endl;
    cout << endl;

    cout << "Testing overloaded << for date objects:" << endl;
    cout << "cout << d << endl;" << endl;
    cout << d << endl;

    return 0;
}