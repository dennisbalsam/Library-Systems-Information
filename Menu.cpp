#include "Menu.h"
#include <iostream>

using namespace std;

//Main menu function
void Menu::MainMenu()
{
	char librarianInput;
	bool backtoMenu = true;
	//Input all data for the library
	LibraryData.setBookInventory("book-data.csv");
	LibraryData.setBorrowerList("borrower-data.csv");



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
	while (backtoMenu == true)
	{
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

		system("cls");
		cout << "Would you like to go back to main menu?: (Y/y for yes, anything else terminates)";
		cin >> librarianInput;
		if (librarianInput == 'Y' || librarianInput == 'y')
			backtoMenu = true;
		else
			backtoMenu = false;

	}
	exit(1); 
}

//Function for returning books
void Menu::ReturnBook()
{   //Local variables
	int month, day, year, id;
	string title;
	BorrowerInformation * CurrentBorrower = nullptr;

	//Prompt librarian for input of information
	cout << "Please enter the 4 digit borrower ID: ";
	cin >> id;
	cout << "Please Enter todays date (in format m d y): ";
	cin >> month >> day >> year;
	cout << "Please enter the title of the book: ";
	cin >> title;
	system("cls");


	//Ensure i aproper month is entered
	if (month < 1 || month > 12)
	{
		cout << "Please enter a valid month: ";
		cin >> month;
	}


	//Ensure a proper day is entered
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day < 1 || day > 31)
		{
			cout << "Please enter a valid day: ";
			cin >> day;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day < 1 || day > 30)
		{
			cout << "Please enter a valid day: ";
			cin >> day;
		}

		break;

	case 2:
		if (day < 1 || day > 28)
		{
			cout << "Please enter a valid day: ";
			cin >> day;
		}
		break;

		if (year < 2019)
		{
			cout << "Please enter a valid year";
			cin >> year;
		}
	}
		//Search for borrower
	do {
		if (CurrentBorrower == nullptr)
		{
			cout << "That is not a valid ID, please enter another ID: " << endl;
			cin >> id;
		}
		CurrentBorrower = LibraryData.getBorrower(id);
	} while (CurrentBorrower == nullptr);

		//call return book function
		LibraryData.returnBook(CurrentBorrower, title, Date(month, day, year));


		delete CurrentBorrower;


	
}

//Function to withdraw books
void Menu::WithdrawBook()
{
	//Local variables
	int month, day, year, id;
	string title;
	BorrowerInformation * CurrentBorrower = nullptr;

	//Prompt librarian for input of information
	cout << "Please enter the 4 digit borrower ID: ";
	cin >> id;

	// check if correct date format
	bool goodDate = false;

	int months31[] = {1, 3, 5, 7, 8, 10, 12};
	int months30[] = {4, 6, 9, 11};
	do
	{
		goodDate = true;

		cout << "Please Enter todays date (in format m d y) ";
		cin >> month >> day >> year;

		// check month
		if(month < 1 || month > 12)
		{
			cout << "Invalid month." << endl;
			goodDate = false;
		}

		// check year
		if(year < 2019)
		{
			cout << "Invalid year." << endl;
			goodDate = false;
		}

		// check day
		if(day < 1)
		{
			cout << "Invalid day." << endl;
			goodDate = false;
		}

		// check 31 day months
		for(int i = 0; i < sizeof(months31)/sizeof(months31[0]); i++)
		{
			if(month == months31[i])
			{
				if(day > 31)
				{
					cout << "Invalid day." << endl;
					goodDate = false;
				}
				break;
			}
		}

		// check 30 day months
		for(int i = 0; i < sizeof(months30)/sizeof(months30[0]); i++)
		{
			if(month == months30[i])
			{
				if(day > 30)
				{
					cout << "Invalid day." << endl;
					goodDate = false;
				}
			}
		}

		// check 28 day month
		if(month == 2 && day > 28)
		{
				cout << "Invalid day." << endl;
				goodDate = false;
		}

	} while(!goodDate);

	cout << "Please enter the title of the book: ";
	cin >> title;
	system("cls");



		//Search for borrower
	do {
		CurrentBorrower = LibraryData.getBorrower(id);
		if (CurrentBorrower == nullptr)
		{
			cout << "That is not a valid ID, please enter another ID: " << endl;
			cin >> id;
		}
	} while (CurrentBorrower == nullptr);
		//call return book function
	if (LibraryData.withdrawBook(CurrentBorrower, title, Date(month, day, year)) == true)
		cout << "Book has been successfully withdrawn" << endl;
	else
		cout << "This book is taken out already" << endl;

		


	delete CurrentBorrower;
}

//Function to search the book inventory
void Menu::SearchBookInventory()
{	
	//Local variables
	string title;
	BookInformation * CurrentBook = nullptr;
	char input;

	//Prompt for title
	cout << "What is the title of the book you wish to search for?: " << endl;
	cin >> title;

	
	do
	{
		CurrentBook = LibraryData.searchInventory(title);
		if (CurrentBook == nullptr)
		{
			cout << "we don't have that book in our library, please enter another book: " << endl;
			cin >> title;
		}
	} while (CurrentBook == nullptr);
	

	cout << "This book is \" " << CurrentBook->getTitle() << "\"" << endl;
	cout << "The author is: " << CurrentBook->getAuthor() << endl;
	cout << "The subject is: " << CurrentBook->getSubject() << endl;
	cout << "Its status is " << CurrentBook->getStatus() << endl;

	system("cls"); 
}

void Menu::ViewInfo()
{
	//Local variables
	int id;
	char input;
	string name, address, phonenumber;
	BorrowerInformation * CurrentBorrower = nullptr;


	//Librarian input
	cout << "Would you like to add a user or view a current users information? " << endl;
	cout << "(A/a) to Add user, (I/i) for an existing users info: ";
	cin >> input;

	switch (input)
	{
	case 'I':
	case 'i':
		cout << "Creating new user" << endl;
		cout << "------------------" << endl;
		//Enter the borrwer name
		cout << "Enter your name: ";
		cin >> name;
		cout << endl;
		//enter borrower address
		cout << "Enter your address: ";
		cin >> address;
		cout << endl;
		//Enter borrower phone number 
		cout << "Enter your phone number: ";
		cin >> phonenumber;
		cout << endl;
		cout << "Enter an ID: ";
		cin >> id;

		//Add the user to the BorrowerList
		LibraryData.addBorrower(name, address, phonenumber, id);

		cout << "You are now a member of our library!!" << endl;
		break;

	case 'A':
	case 'a':
		//Ask the borrower for their ID, and input it to the system
		cout << "Enter the users ID: " ;
		cin >> id;

		//Search for User
		do {
			if (CurrentBorrower == nullptr)
			{
				cout << "That is not a valid ID, please enter another ID: " << endl;
				cin >> id;
			}
			CurrentBorrower = LibraryData.getBorrower(id);
		} while (CurrentBorrower == nullptr);
		//Output UserInfo
		cout << "Borrower Name: " << CurrentBorrower->getName() << endl;
		cout << "Borrower Address: " << CurrentBorrower->getAddress() << endl;
		cout << "Borrower Phone Number: " << CurrentBorrower->getPhoneNumber() << endl;
		cout << "Borrower ID: " << CurrentBorrower->getId() << endl;
		cout << "Borrower Fees Owed: " << CurrentBorrower->getFeeBalance() << endl;
		cout << "Amount of Books the Borrower currently has: " << CurrentBorrower->getBookAmount(); 

		break;
	}
}