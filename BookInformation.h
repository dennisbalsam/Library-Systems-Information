#include <string>
#include "Date.h"
#include <iostream>
using namespace std;

class BookInformation
{
private:
	string title, author, subject, id, publisher;
	Date publishingDate, dueDate;
	int status, circulationPeriod, location;
	double costOfBook, finePerDayOverdue;
public:
	BookInformation();
	BookInformation(string t, string a, string s, string i) : title(t), author(a), subject(s), id(i) {}

	void setTitle(string t);
	void setAuthor(string a);
	void setSubject(string s);
	void setID(string i);
	void setPublisher(string p);

	void setPublishingDate(Date d);
	void setDueDate(Date d);

	void setLocation(int l);
	void setStatus(int s); // int values: [ 0: Unavailable / 1: Available / 2: Hold / 3: Maintenance ]
	void setCirculationPeriod(int c); // int value in amount of DAYS

	void setCostOfBook(double c); // $ - . - -
	void setFinePerDayOverdue(double f);
	void setFinePerDayOverdue();

	string getTitle();
	string getAuthor();
	string getSubject();
	string getID();
	string getPublisher();

	Date getPublishingDate();
	Date getDueDate();

	int getLocation();
	int getStatus();
	int getCirculationPeriod();

	double getCostOfBook();
	double getFinePerDayOverdue();

	void print();
};
