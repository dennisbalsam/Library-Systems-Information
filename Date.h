
#include <iostream>

using namespace std;

class Date
{
private:
	int day, month, year;
public:
	Date() : day(0), month(0), year(0) {}
	Date(int m, int d, int y) : day(d), month(m), year(y) {}
	void setDay(int d) { day = d; }
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
				if (day > 28)
				{
					month++;
					day = day - 28;
				}


		}

		
	}
	int dateDiff(Date D2)
	{
		int daysinyear[] = {0,31,59,90,120,151,181,212,243,273,304,334,365 };

		int days;
		days = (daysinyear[month - 1] + day) - (daysinyear[D2.month - 1] + (D2.day));
		return days;
	}
};


