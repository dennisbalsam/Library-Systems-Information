#include "BookInformation.h"
BookInformation::BookInformation()
{
	title = "Null";
	author = "Null";
	subject = "Null";
	id = "Null";
	publisher = "Null";
}

//Mutator Function Definitions
void BookInformation::setTitle(string t) { title = t; }
void BookInformation::setAuthor(string a) { author = a; }
void BookInformation::setSubject(string s) { subject = s; }
void BookInformation::setID(string i) { id = i; }
void BookInformation::setPublisher(string p) { publisher = p; }

void BookInformation::setPublishingDate(Date d) { publishingDate = d; }
void BookInformation::setDueDate(Date d) { dueDate = d; }

void BookInformation::setFinePerDayOverdue(double f) { finePerDayOverdue = f; }
void BookInformation::setFinePerDayOverdue() { finePerDayOverdue = 0.15 * costOfBook; } //15% of book cost = fee
void BookInformation::setCostOfBook(double c) { costOfBook = c; }

void BookInformation::setLocation(int l) { location = l; }
void BookInformation::setStatus(int s) { status = s; }
void BookInformation::setCirculationPeriod(int c) { circulationPeriod = c; }

//Accessor Function Definitions
string BookInformation::getTitle() { return title; }
string BookInformation::getAuthor() { return author; }
string BookInformation::getSubject() { return subject; }
string BookInformation::getID() { return id; }
string BookInformation::getPublisher() { return publisher; }

Date BookInformation::getPublishingDate() { return publishingDate; }
Date BookInformation::getDueDate() { return dueDate; }

double BookInformation::getFinePerDayOverdue() { return finePerDayOverdue; }
double BookInformation::getCostOfBook() { return costOfBook; }

int BookInformation::getLocation() { return location; }
int BookInformation::getStatus() { return status; }
int BookInformation::getCirculationPeriod() { return circulationPeriod; }

void BookInformation::print()
{
	cout << "Title: " << title << " Author: " << author << " ID: " << id << endl;
}
