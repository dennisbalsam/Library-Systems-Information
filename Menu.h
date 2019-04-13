#pragma once
#include <iostream>
#include "Date.h"
#include "LibraryInventory.h"
#include "BookInformation.h"
#include "BorrowerInformation.h"

using namespace std;

class Menu {

	private: 
		//Have all the library data at your disposable 
		LibraryInventory LibraryData;

	public:
		//Menu that pops up when program is loaded
		void MainMenu(); //will intiialize the loading of books and people

		//Function to return books
		void ReturnBook();

		//Function to take books out
		void WithdrawBook();

		//Function to serach the inventory of books
		void SearchBookInventory();

		//Function to view borrower information
		void ViewInfo();




};