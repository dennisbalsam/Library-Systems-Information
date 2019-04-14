#include <iostream>
#include "../LibraryInventory.h"
#include "../BookInformation.h"
using namespace std;

int main()
{
	LibraryInventory l;
	l.setBookInventory("../book-data.csv");

	BookInformation *b = l.searchInventory("Twilight");
	if(b)
	{
		cout << "Title: " << b->getTitle() << endl;
		cout << "Author: " << b->getAuthor() << endl;
		cout << "Subject: " << b->getSubject() << endl;
		cout << "Publisher: " << b->getPublisher() << endl;
		cout << "Publisblishing date: " << b->getPublishingDate() << endl;
		cout << "Due date: " << b->getDueDate() << endl;
		cout << "Circulation period: " << b->getCirculationPeriod() << endl;
		cout << "Location: " << b->getLocation() << endl;
		cout << "ID: " << b->getID() << endl;
		cout << "Cost: " << b->getCostOfBook() << endl;
		cout << "Overdue fine: " << b->getFinePerDayOverdue() << endl;
	}
	

	return 0;
}
