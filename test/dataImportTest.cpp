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
		cout << *b << endl;

	return 0;
}
