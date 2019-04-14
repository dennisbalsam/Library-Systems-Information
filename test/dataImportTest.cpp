#include <iostream>
#include "../LibraryInventory.h"
#include "../BookInformation.h"
using namespace std;

int main()
{
	LibraryInventory l;
	l.setBookInventory("../book-data.csv");
	l.setBorrowerList("../borrower-data.csv");

	// test book info import
	BookInformation *b = l.searchInventory("Twilight");
	if(b)
		cout << *b << endl;

	// test borrower info import
	BorrowerInformation *b2 = l.getBorrower(16800);
	cout << b2->getAddress() << endl;

	return 0;
}
