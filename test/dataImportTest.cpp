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
		cout << b->getTitle() << endl;
		cout << b->getAuthor() << endl;
		cout << b->getSubject() << endl;
		cout << b->getPublisher() << endl;
	}
	

	return 0;
}
