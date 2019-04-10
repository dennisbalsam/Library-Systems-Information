#include "BookInformation.h"

void BookInformation::setTitle(String t) { title = t; }
void BookInformation::setAuthor(String a) { author = a; }
void BookInformation::setSubject(String s) { subject = s; }
void BookInformation::setID(String i) { id = i; }
void BookInformation::setPublisher(String p) { publisher = p; }

void BookInformation::setPublishingDate(Date d) { publishingDate = d; }
void BookInformation::setPublishingDate(int d, int m, int y) { Date d(d, m, y); publishingDate = d; }
void BookInformation::setDueDate(Date d) { dueDate = d; }
void BookInformation::setDueDate(int d, int m, int y) { Date d(d, m, y); dueDate = d; }

void BookInformation::setFinePerDayOverdue(double f) { finePerDayOverdue = f; }
void BookInformation::setFinePerDayOverdue() { finePerDayOverdue = 0.15 * costOfBook; } //15% of book cost = fee
void BookInformation::setCostOfBook(double c) { costOfBook = c; }

void BookInformation::setLocation(int l) { location = l; }
void BookInformation::setStatus(int s) { status = s; }
void BookInformation::setCirculationPeriod(int c) { circulationPeriod = c; }

String BookInformation::getTitle() { return title; }
String BookInformation::getAuthor() { return author; }
String BookInformation::getSubject() { return subject; }
String BookInformation::getID() { return id; }
String BookInformation::getPublisher() { return publisher; }

Date BookInformation::getPublishingDate() { return publishingDate; }
Date BookInformation::getDueDate() { return dueDate; }

double BookInformation::getFinePerDayOverdue() { return finePerDayOverdue; }
double BookInformation::getCostOfBook() { return costOfBook; }

int BookInformation::getLocation() { return location; }
int BookInformation::getStatus() { return status; }
int BookInformation::getCirculationPeriod() { return circulationPeriod; }
