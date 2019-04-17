#include <iostream>
#include "../Date.h"

using namespace std;

enum DATE
{
    MONTH,
    DAY,
    YEAR
};

int main()
{
    // general date constructor
    Date d(3, 10, 2020);

    // test setters and getters
    int dateDesired[] = {5, 22, 2025};

    cout << "Date desired:" << endl;
    for (auto i : dateDesired)
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
    d.setDate(dateDesired[MONTH] + 1, dateDesired[DAY] + 1, dateDesired[YEAR] + 1);
    cout << "New current date:" << endl;
    cout << d.getMonth() << " ";
    cout << d.getDay() << " ";
    cout << d.getYear() << endl;
    cout << endl;

    // Testing overloaded << for date objects
    cout << "Testing overloaded << for date objects:" << endl;
    cout << "cout << d << endl;" << endl;
    cout << d << endl;
    cout << endl;

    // testing increaseDate function
    cout << "testing increaseDate function:" << endl;
    cout << "increaseDate (int days)" << endl;
    cout << endl;

    // months with 31 days
    int month31[] = {1, 3, 5, 7, 8, 10, 12};
    // months with 30 days
    int month30[] = {4, 6, 9, 11};

    cout << "Testing increaseDate with 31 day months:" << endl;

    cout << "d.setDate(month, 31, 2020)" << endl;
    for (auto month : month31)
    {
        cout << "-------------------" << endl;
        d.setDate(month, 31, 2020);
        cout << "Month: " << d.getMonth() << endl;
        cout << "Before increaseDate" << endl;
        cout << d << endl;
        cout << "After increaseDate" << endl;
        d.increaseDate(1);
        cout << d << endl;
        cout << "-------------------" << endl;
    }

    // Testing increaseDate with 30 day months
    cout << "Testing increaseDate with 30 day months:" << endl;

    cout << "d.setDate(month, 30, 2020)" << endl;
    for (auto month : month30)
    {
        cout << "-------------------" << endl;
        d.setDate(month, 30, 2020);
        cout << "Month: " << d.getMonth() << endl;
        cout << "Before increaseDate" << endl;
        cout << d << endl;
        cout << "After increaseDate" << endl;
        d.increaseDate(1);
        cout << d << endl;
        cout << "-------------------" << endl;
    }

    // Testing increaseDate with February (28 days)
    cout << "Testing increaseDate with February (28 days)" << endl;

    cout << "d.setDate(2, 28, 2019)" << endl;
    d.setDate(2, 28, 2019);
    cout << "Month: " << d.getMonth() << endl;
    cout << "Before increaseDate" << endl;
    cout << d << endl;
    cout << "After increaseDate" << endl;
    d.increaseDate(1);
    cout << d << endl;

    return 0;
}