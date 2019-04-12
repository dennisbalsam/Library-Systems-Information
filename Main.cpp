

#include <iostream>
#include <ctime>
#include "Date.h"
#include "LibraryInventory.h"
#include "BookInformation.h"
#include "BorrowerInformation.h"
using namespace std;

int main()
{
	LibraryInventory L1;
	L1.setBookInventory("Input.txt");

	// EDIT
	// BB1 is a BookInformation ptr
	BookInformation * BB1 = L1.searchInventory("life");



	BorrowerInformation * B1;

	L1.addBorrower("Dennis", "488 Tarrytown Ave", "13478505621", 2035);

	B1 = L1.getBorrower(2035);

	L1.withdrawBook(B1, "life", Date(4, 10, 2019));
	cout << BB1->getStatus() << endl;
	L1.returnBook(B1, "life", Date(4, 25, 2019));
	cout << B1->getFeeBalance() << endl;
	cout << BB1->getStatus() << endl;

	cout << B1->hasBook("life") << endl;


	system("pause");
	return 0;
}
