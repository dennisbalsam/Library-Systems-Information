#pragma once


#include <string>
#include "Date.h"
#include <iostream>
using namespace std;

class BookInformation
{
private:
	string title, author, subject, publisher;
	Date publishingDate, dueDate;
	int status, circulationPeriod, location, id;
	double costOfBook, finePerDayOverdue;
public:
	BookInformation();
	BookInformation(string t, string a, string s, string p, int i) : title(t), author(a), subject(s), publisher(p), id(i) 
	{ 
		publishingDate = Date(0,0,0); 
		dueDate = Date(0, 0, 0);
		status = 1;
		circulationPeriod = 0;
		location = 0;
		costOfBook = 0.0;
		finePerDayOverdue = 0;
	}

	void setTitle(string t);
	void setAuthor(string a);
	void setSubject(string s);
	void setID(int i);
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
	string getPublisher();

	Date getPublishingDate();
	Date getDueDate();

	int getLocation();
	int getStatus();
	int getCirculationPeriod();
	int getID();

	double getCostOfBook();
	double getFinePerDayOverdue();

	void print();
};


