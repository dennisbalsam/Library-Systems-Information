#pragma once
#include <string>
#include <vector>
#include "BookInformation.h"

using namespace std;

class BorrowerInformation
{
	string name;
	string address;
	string phoneNumber;
	int id;
	vector<BookInformation *> books;
	double feeBalance;

public:
	// default constructor
	BorrowerInformation() : name("NO_NAME"), address("NO_ADDRESS"), phoneNumber("NO_PHONENUMBER"), id(0), feeBalance(0) {};
	// general constructor: requires at least a name
	BorrowerInformation(const string &n, const string &a = "NO_ADDRESS", const string &p = "NO_PHONENUMBER", const int &i = 0, const double &f = 0) : name(n), address(a), phoneNumber(p), id(i), feeBalance(f) {};

	// setters
	void setName(const string &n) { name = n; };
	void setAddress(const string &a) { address = a; };
	void setPhoneNumber(const string &p) { phoneNumber = p; };
	void setId(const int &i) { id = i; };
	void setFeeBalance(const double &f) { feeBalance = f; };
	// add book to borrower's books
	void addBook(BookInformation *book) { books.push_back(book); };
	//remove book from borrowers book list
	void returnBook(BookInformation * book)
	{
		for (int s = 0; s < books.size(); s++)
		{
			if (book->getTitle() == books[s]->getTitle())
				books.erase(books.begin() + s); 
		}

	}
	// getters
	string getName() { return name; };
	string getAddress() { return address; };
	string getPhoneNumber() { return phoneNumber; };
	int getId() { return id; };
	double getFeeBalance() { return feeBalance; };
	// check if borrower has book
	
	bool hasBook(const string &bookname)
	{
		for (auto book : books)
		{
			if (book->getTitle() == bookname)
				return true;
		}
		return false;
	};
	
};