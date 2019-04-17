#pragma once

#include <iostream>
using namespace std;

class Date
{
private:
	int day, month, year;
public:
	Date() : day(0), month(0), year(0) {}
	Date(int m, int d, int y): month(m), day(d), year(y)
	{
	}
	void setDay(int d)  {day = d; }
	void setMonth(int m) { month = m; }
	void setYear(int y) { year = y; }
	void setDate (int m, int d, int y) { day = d; month = m; year = y; }
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	friend ostream& operator<<(ostream& os, const Date& dt) //overload output operator to output date easier
	{
		os << dt.month << "/" << dt.day << "/" <<  dt.year << endl;
		return os;
	}
	void increaseDate (int days) 
	{

		day += days;
		switch (month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10: 
			case 12:
				if (day > 31)
				{
					if (month != 12)
					{
						month++;
						day = day - 31;
					}
					else if (month == 12)
					{
						month = 1;
						day = day - 31;
						year++;
					}
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30)
				{
					month++;
					day = day - 30;
				}
				break;
			case 2:
				if (year % 4 == 0 || year % 100 == 0 || year % 400 == 0)
				{
					if (day > 29)
					{
						month++;
						day = day - 29;
					}

				}
				else {
					if (day > 28)
					{
						month++;
						day = day - 28;
					}
				}


		}

		
	}
	int dateDiff(Date D2)
	{
		int days;

		int yearDifference;

		//Check if the year is a leap year
		if (year % 4 == 0 || year % 100 == 0 || year % 400 == 0)
		{
			int daysinyear[] = { 0,31,60,91,121,152,182,213,244,274,305,335,366 };
			yearDifference = (year - D2.year);
			if (yearDifference >= 1)
			{
				//variables to help calculate days
				int daysinoriginalyear, additionaldays;
				//calculate days in previous year
				daysinoriginalyear = (365 - ((daysinyear[D2.month - 1] + D2.day)));
				//calculate days in new year
				additionaldays = (yearDifference * 365) - (365 - day);
				// add up the days to get toal days overdue
				days = daysinoriginalyear + additionaldays;
			}
			else
			{
				days = (daysinyear[month - 1] + day) - (daysinyear[D2.month - 1] + (D2.day));
				cout << days;
			}
		}

		else {
			int daysinyear[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
			yearDifference = (year - D2.year);
			if (yearDifference >= 1)
			{
				//variables to help calculate days
				int daysinoriginalyear, additionaldays;
				//calculate days in previous year
				daysinoriginalyear = (365 - ((daysinyear[D2.month - 1] + D2.day)));
				//calculate days in new year
				additionaldays = (yearDifference * 365) - (365 - day);
				// add up the days to get toal days overdue
				days = daysinoriginalyear + additionaldays;
			}
			else
			{
				days = (daysinyear[month - 1] + day) - (daysinyear[D2.month - 1] + (D2.day));
				cout << days;
			}
		}
		return days;
	}
};


