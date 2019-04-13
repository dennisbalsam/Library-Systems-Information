#include "Menu.h"
#include <iostream>

using namespace std;

//Main menu function
void Menu::MainMenu()
{
	char librarianInput;
	//Input all data for the library
	LibraryData.setBookInventory("Input.txt");



	//Welcoming messages
	cout << "Welcome to the Library Master 3000" << endl;
	cout << "What would you like to do today?: " << endl;
	cout << "(W/w for withdrawing books)" << endl;
	cout << "(R/r for return books)" << endl;
	cout << "(S/s to search the inventory)" << endl;
	cout << "(V/v to view a borrowers information)" << endl;
	cin >> librarianInput;
	cout << endl;

	//Enter desired submenu
	switch (librarianInput)
	{
	case 'W':
	case 'w':
		this->WithdrawBook();
		break;
	case 'R':
	case 'r':
		this->ReturnBook();
		break;
	case 'S':
	case 's':
		this->SearchBookInventory();
		break;
	case 'V':
	case 'v':
		this->ViewInfo();
		break;
	}
}