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
	string id;
	vector<BookInformation *> books;
	double feeBalance;

	public:
		// default constructor
		BorrowerInformation() : name("NO_NAME"), address("NO_ADDRESS"), phoneNumber("NO_PHONENUMBER"), id("NO_ID"), feeBalance(0) {};
		// general constructor: requires at least a name
		BorrowerInformation(const string &n, const string &a="NO_ADDRESS", const string &p="NO_PHONENUMBER", const string &i="NO_ID", const double &f=0) : name(n), address(a), phoneNumber(p), id(i), feeBalance(f) {};

		// setters
		void setName(const string &n){ name = n; };
		void setAddress(const string &a){ address = a; };
		void setPhoneNumber(const string &p){ phoneNumber = p; };
		void setId(const string &i){ id = i; };
		void setFeeBalance(const double &f){ feeBalance = f; };
		// add book to borrower's books
		void addBook(BookInformation *book){ books.push_back(book); };
		// set book properties: find book by name, then set.
		bool setBookStatus(const string &bookName);
		bool setBookFine(const string &bookName);
		bool setBookDueDate(const string &bookName);

		// getters
		string getName(){ return name; };
		string getAddress(){ return address; };
		string getPhoneNumber(){ return phoneNumber; };
		string getId(){ return id; };
		double getFeeBalance(){ return feeBalance; };
		// get book: find book by name, return pointer from vector
		bool getBook(const string &bookName);
};