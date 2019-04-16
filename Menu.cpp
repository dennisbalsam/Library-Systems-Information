#include "Menu.h"

//Main menu function
void Menu::MainMenu()
{
	char librarianInput;
	int backToMenu = 0;
	bool backtoMenu = true;
	//Input all data for the library
	LibraryData.setBookInventory("book-data.csv");
	LibraryData.setBorrowerList("borrower-data.csv");




	//Enter desired submenu
	while (backtoMenu == true)
	{
		system("cls");
		//Welcoming messages
		cout << "Welcome to the Library Master 3000" << endl;
		cout << "What would you like to do today?: " << endl;
		cout << "(T/t for transaction of withdrawing books)" << endl;
		cout << "(S/s to search the inventory)" << endl;
		cout << "(V/v to view a borrowers information)" << endl;
		cin >> librarianInput;
		cout << endl;

		switch (librarianInput)
		{
		case 'T':
		case 't':
			this->BookTransaction(backToMenu);
			break;
		case 'S':
		case 's':
			this->SearchBookInventory(backToMenu);
			break;
		case 'V':
		case 'v':
			this->ViewInfo(backToMenu);
			break;
		}


		if (backToMenu == 1)
			backtoMenu = true;
		else 
			backtoMenu = false;

	}
	exit(1); 
}


//Function to withdraw books
void Menu::BookTransaction(int & librarianinput)
{




	//Local variables
	int month, day, year, id;
	char transactionType;
	string title;
	BorrowerInformation * CurrentBorrower = nullptr;


	// Ask if they want to return or wihthdraw a book
	cout << "Are you returning or withdrawing a book?(R/r for return, W/w for withdraw) : ";
	cin >> transactionType; 

	//Prompt librarian for input of information
	cout << "Please enter the 5 digit borrower ID: ";
	cin >> id;
	//Search for borrower
	do {
		CurrentBorrower = LibraryData.getBorrower(id);
		if (CurrentBorrower == nullptr)
		{
			cout << "That is not a valid ID, please enter another ID: " << endl;
			cin >> id;
		}
	} while (CurrentBorrower == nullptr);

	// check if correct date format
	bool goodDate = false;
	bool leapyear = false;
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
		if(month == 2)
		{

			if (year % 4 == 0 || year % 100 == 0 || year % 400 == 0)
			{
						leapyear = true;
			}
			if (day > 28 && leapyear == false)
			{
				cout << "Invalid day." << endl;
				goodDate = false;
			}
			else if (day > 29 && leapyear == true)
				goodDate = true;
			else if (day > 29 && leapyear == true)
				goodDate = false;
		}

	} while(!goodDate);


	cout << "Please enter the title of the book: " << endl;
	cin.ignore();
	getline(cin, title);  //to input with whitespace




	if (transactionType == 'W' || transactionType == 'w')
	{
		if (LibraryData.withdrawBook(CurrentBorrower, title, Date(month, day, year)) == true)
			cout << "Book has been successfully withdrawn" << endl;
		else
			cout << "This book is taken out already" << endl;
	}
	else if (transactionType == 'R' || transactionType == 'r')
	{
		//call return book function
		LibraryData.returnBook(CurrentBorrower, title, Date(month, day, year));
		cout << "Book successfully returned" << endl;
	}




	cout << "Please enter 1 to return to main menu || Enter anything else to terminate program: ";
	cin >> librarianinput;


}

//Function to search the book inventory
void Menu::SearchBookInventory(int & librarianinput)
{	
	//Local variables
	string title;
	BookInformation * CurrentBook = nullptr;
	char choice;
	cout << "Would you like to view the entire inventory or serach for a particular book?" << endl;
	cout << "A/a for all books || B/b for particular book" << endl;
	cin >> choice;


	if (choice == 'A' || choice == 'a')
	{
		cout << "ALL BOOKS IN LIBRARY" << endl;
		cout << "----------------------------" << endl;
		LibraryData.printBookInventory();
	}
	
	else if (choice == 'B' || choice == 'b')
	{
	

		cout << "Please enter the title of the book: " << endl;
		cin.ignore();
		getline(cin, title);  //to input with whitespace


		do
		{
			CurrentBook = LibraryData.searchInventory(title);
			if (CurrentBook == nullptr)
			{
				cout << "we don't have that book in our library, please enter another book: " << endl;
				getline(cin, title);
			}
		} while (CurrentBook == nullptr);

		cout << *CurrentBook;

	}
	cout << "Please enter 1 to return to main menu || Enter anything else to terminate program: ";
	cin >> librarianinput;

}

void Menu::ViewInfo(int & librarianinput)
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
	case 'A':
	case 'a':
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
		cout << "Enter a 5 digit ID: ";
		cin >> id;

		//Add the user to the BorrowerList
		LibraryData.addBorrower(name, address, phonenumber, id);

		cout << "You are now a member of our library!!" << endl;
		break;

	case 'I':
	case 'i':
		//Ask the borrower for their ID, and input it to the system
		cout << "Enter the 5 digit user ID: " ;
		cin >> id;

		//Search for User
		do {
			CurrentBorrower = LibraryData.getBorrower(id);
			if (CurrentBorrower == nullptr)
			{
				cout << "That is not a valid ID, please enter another ID: " << endl;
				cin >> id;
			}
		} while (CurrentBorrower == nullptr);
		//Output UserInfo
		cout << *CurrentBorrower;

		break;
	}


	cout << "Please enter 1 to return to main menu || Enter anything else to terminate program: ";
	cin >> librarianinput;

}