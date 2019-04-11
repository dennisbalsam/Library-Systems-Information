class Date
{
private:
	int day, month, year;
public:
	Date() : day(1), month(1), year(2019) {}
	Date(int d, int m, int y): day(d), month(m), year(y) {}
	void setDay(int d) { day = d; }
	void setMonth(int m) { month = m; }
	void setYear(int y) { year = y; }
	void setDate(int d, int m, int y) { day = d; month = m; year = y; }
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
};
