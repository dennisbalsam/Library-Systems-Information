#include "LibraryInventory.h"
#include "Date.h"
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

enum bookAttributes { TITLE, AUTHOR, SUBJECT, PUBLISHER, PUBLISHINGDATE, ID, FINEPERDAYOVERDUE, COSTOFBOOK, LOCATION, CIRCULATIONPERIOD };

//Function to search the inventory of books
BookInformation *LibraryInventory::searchInventory(string title)
{

	//Loop to find book
	for (int x = 0; x < BookInventory.size(); x++)
	{
		if (title == BookInventory[x].getTitle())
		{
			return &BookInventory[x];
		}
	}

	return nullptr; // book was not found
}

//Function to serach for borrower
BorrowerInformation *LibraryInventory::getBorrower(int id)
{ 
	for (int i = 0; i < BorrowerList.size(); i++)
	{
		if (id == BorrowerList[i].getId())
		{
			return &BorrowerList[i]; 
		}
	}
	// borrower not found
	return nullptr;

}




//Function to change status
void LibraryInventory::changeStatus(Status newStatus, BookInformation * Book)
{
	if(Book) // if book is not nullptr
		Book->setStatus(newStatus);
}

//Function to import the books
void LibraryInventory::setBookInventory(string name)
{
	//Temp strings
	string title, author, subject, publisher; 
	//int to input books 
	int currentBook = 0, id = 0;


	//Declare inpput file name
	ifstream infile;

	//open the file
	infile.open(name);

	//Make sure the file opened
	if (infile.fail())
	{
		cout << "Input file did not open" << endl;
		exit(1);
	}

	// tokenize file
	// Then push each book into the vector

	string line; // file line buffer
	string tok; // line token buffer
	bool firstLine = true; // if first line of data
	vector<string> lineTokens; // tokens found in line
	while(getline(infile, line)) // newline delimiter
	{
		stringstream ss(line); // stringstream from line

		// handling first line of data (do not import)
		if(firstLine)
			firstLine = false;
		else
		{
			while(getline(ss, tok, ',')) // comma delimiter
			{
				lineTokens.push_back(tok);
			}
				BookInventory.push_back(BookInformation(lineTokens[TITLE], lineTokens[AUTHOR], lineTokens[SUBJECT], lineTokens[PUBLISHER], atoi(lineTokens[ID].c_str()))); 

				// set publishing date
				BookInventory.back().setPublishingDate( Date(1,2,atoi(lineTokens[PUBLISHINGDATE].c_str())) );
				
				// set circulation period
				BookInventory.back().setCirculationPeriod(atoi(lineTokens[CIRCULATIONPERIOD].c_str()));

				// set location
				BookInventory.back().setLocation(atoi(lineTokens[LOCATION].c_str()));

				// set cost of book
				BookInventory.back().setCostOfBook(atoi(lineTokens[COSTOFBOOK].c_str()));

				// set fine
				BookInventory.back().setFinePerDayOverdue(atoi(lineTokens[FINEPERDAYOVERDUE].c_str()));

				lineTokens.clear();
		}

	}

	//CLose the file
	infile.close();



}


//Function to withdraw the book
bool LibraryInventory::withdrawBook(BorrowerInformation * B1, string title, Date todaysDate)
{
	//Find desired book 
	BookInformation * book = searchInventory(title);

	//Statement to return false if book is unavailable 
	// if book is nullptr or has status != AVAILABLE
	if(!book || book->getStatus() != AVAILABLE)
		return false;
	else {

		//Set the due date based on the circulation period and the current date
		book->setStatus(UNAVAILABLE);
		book->setCirculationPeriod(14);
		//Set the due date, and fine per day
		todaysDate.increaseDate(book->getCirculationPeriod());

		book->setDueDate(todaysDate);
		book->setFinePerDayOverdue(3.00);

		//Add the book to the list of books the borrower has
		B1->addBook(book);

		return true;

		delete book;
	}
}

//Function to return books
bool LibraryInventory::returnBook(BorrowerInformation * B1, string title, Date todaysDate)
{
	//Find desired book 
	BookInformation * book = searchInventory(title);

	// if book was not found
	if(!book)
		return false;

	//Check if it is late, if so add a fee to the users account
	int daysOverdue = todaysDate.dateDiff(book->getDueDate());
	double fee = daysOverdue * book->getFinePerDayOverdue();
	if (daysOverdue > 0)
		B1->setFeeBalance(fee);

	//Change the book status
	book->setStatus(AVAILABLE);

	//Change circulation period to 0
	book->setCirculationPeriod(0);

	//Change due date to 0
	book->setDueDate(Date(0, 0, 0));

	//Remove the book from the borrowers list
	B1->returnBook(book);

	delete book;

	return true;


}




//function to add borrower to system
void LibraryInventory::addBorrower(string name, string address, string phonenumber , int id)
{
	//Add a borrower
	BorrowerList.push_back(BorrowerInformation(name, address, phonenumber, id));


}