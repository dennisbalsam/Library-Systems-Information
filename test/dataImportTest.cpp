#include <iostream>
#include "../LibraryInventory.h"
#include "../BookInformation.h"
using namespace std;

int main()
{
	LibraryInventory l;
	l.setBookInventory("../book-data.csv");
	l.setBorrowerList("../borrower-data.csv");

	// print lists
	l.printBookInventory();
	l.printBorrowerList();


	return 0;
}
