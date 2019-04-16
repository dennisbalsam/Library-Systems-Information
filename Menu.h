#pragma once
#include <iostream>
#include "Date.h"
#include "LibraryInventory.h"
#include "BookInformation.h"
#include "BorrowerInformation.h"
#include <string>

using namespace std;

class Menu {

	private: 
		//Have all the library data at your disposable 
		LibraryInventory LibraryData;

	public:
		//Menu that pops up when program is loaded
		void MainMenu(); //will intiialize the loading of books and people

		//Function to take books out
		void BookTransaction(int &);

		//Function to serach the inventory of books
		void SearchBookInventory(int &);

		//Function to view borrower information
		void ViewInfo(int &);




};