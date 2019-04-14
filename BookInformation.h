#pragma once

#include <string>
#include "Date.h"
#include <iostream>
using namespace std;

// book statuses
enum Status { UNAVAILABLE, AVAILABLE, HOLD, MAINTENANCE, TOTAL_STATUS };

class BookInformation
{
private:

	string title, author, subject, publisher;
	Date publishingDate, dueDate;
	Status status;
	int circulationPeriod, location, id;
	double costOfBook, finePerDayOverdue;
public:
	BookInformation();
	BookInformation(string t, string a, string s, string p, int i) : title(t), author(a), subject(s), publisher(p), id(i)
	{
		publishingDate = Date(0, 0, 0);
		dueDate = Date(0, 0, 0);
		status = AVAILABLE;
		circulationPeriod = 0;
		location = 0;
		costOfBook = 0.0;
		finePerDayOverdue = 0;
	}

	friend ostream& operator<<(ostream& os, BookInformation& b)
	{
		os << "Title: " << b.getTitle() << endl;
		os << "Author: " << b.getAuthor() << endl;
		os << "Subject: " << b.getSubject() << endl;
		os << "Publisher: " << b.getPublisher() << endl;
		os << "Publisblishing date: " << b.getPublishingDate() << endl;
		os << "Due date: " << b.getDueDate() << endl;
		os << "Circulation period: " << b.getCirculationPeriod() << endl;
		os << "Location: " << b.getLocation() << endl;
		os << "ID: " << b.getID() << endl;
		os << "Cost: " << b.getCostOfBook() << endl;
		os << "Overdue fine: " << b.getFinePerDayOverdue() << endl;
		return os;
	}


	void setTitle(string t);
	void setAuthor(string a);
	void setSubject(string s);

	void setID(int i);

	void setPublisher(string p);

	void setPublishingDate(Date d);
	void setDueDate(Date d);

	void setLocation(int l);
	void setStatus(Status s); // int values: [ 0: Unavailable / 1: Available / 2: Hold / 3: Maintenance ]
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
	Status getStatus();
	int getCirculationPeriod();
	int getID();

	double getCostOfBook();
	double getFinePerDayOverdue();

	void print();
};
