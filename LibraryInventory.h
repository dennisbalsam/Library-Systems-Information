#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "BookInformation.h"
#include "BorrowerInformation.h"

using namespace std;

class LibraryInventory
{
	private:
		
		//Vector store all the books in the library
		vector<BookInformation> BookInventory;
		vector<BorrowerInformation> BorrowerList; 
		//Int to keep track of amount of books in the inventory
		int quantity;
		

	public:

		//Gets and sets
		int getQuantity() { return quantity; };
		void setQuantity(int quantity) { this->quantity = quantity; };
		
		//Search the inventory of books
			BookInformation * searchInventory(string title);
			//Set the inventory of books and users
			void setBookInventory(string);
			// set list of borrowers
			void setBorrowerList(string);

			//Function to alter the of books in the book inventory
			void changeStatus(Status newStatus, BookInformation * Book);

			//Functions to withdraw and return books 
			bool withdrawBook(BorrowerInformation * B1, string title, Date todaysDate);

			bool returnBook(BorrowerInformation * B1, string title, Date todaysDate);

			//FUnction to create borrower
			void addBorrower(string, string, string, int); 

			//Function get book info
			BorrowerInformation * getBorrower(int id);


};

