#include <iostream>
#include "../LibraryInventory.h"

using namespace std;

int main()
{
    LibraryInventory l;

    // Preliminary data
    // ================

    // data file paths
    const char *bookData = "../book-data.csv";
    const char *borrowerData = "../borrower-data.csv";

    // expected borrower name and ID
    const char *borrowerName = "Abbot Morrow";
    const int borrowerID = 16770;

    // expected book title
    const char *bookTitle = "Charlotte's Web";

    // A single book
    BookInformation *b;

    // A single borrower
    BorrowerInformation *br;

    // today's date
    Date today(4,17,2019);

    // ================

    // setting inventory and borrower list
    cout << "Setting inventory and borrower list:" << endl;

    cout << "Book data file: " << bookData << endl;
    cout << "Borrower data file: " << borrowerData << endl;
    cout << endl;

    cout << "l.setBookInventory(bookData)" << endl;
    cout << "l.setBorrowerList(borrowerData)" << endl;
    l.setBookInventory(bookData);
    l.setBorrowerList(borrowerData);
    cout << endl;

    // Printing book inventory
    cout << "Printing book inventory:" << endl;
    cout << "======================== " << endl;
    cout << "l.printbookinventory()" << endl;
    l.printBookInventory();
    cout << endl;

    // Printing borrower list
    cout << "Printing borrower list:" << endl;
    cout << "======================== " << endl;
    cout << "l.printBorrowerList()" << endl;
    l.printBorrowerList();
    cout << endl;

    // Testing Inventory Searching
    cout << "Testing Inventory Searching: " << endl;
    cout << "Book title: " << bookTitle << endl;
    cout << "BookInformation *b = l.searchInventory(bookTitle);" << endl;
    b = l.searchInventory(bookTitle);
    cout << "cout << b->getTitle() << endl" << endl;
    cout << b->getTitle() << endl;
    cout << endl;


    // Testing book status changing function
    cout << "Testing book status changing function:" << endl;
    cout << "changeStatus(Status newStatus, BookInformation * Book)" << endl;
    cout << "b->getStatus()" << endl;
    cout << "Book's current status:" << endl;
    cout << b->getStatus() << endl;
    cout << "After changing status to unavailable:" << endl;
    l.changeStatus(UNAVAILABLE, b);
    cout << b->getStatus() << endl;
    cout << endl;
    l.changeStatus(AVAILABLE, b);

    // Testing withdraw function 
    cout << "Testing withdraw function:" << endl;
    cout << "==========================" << endl;
    cout << "Checking status of book before withdraw:" << endl;
    cout << *b << endl;
    cout << "==========================" << endl;
    cout << endl;

    cout << "Setting borrower:" << endl;
    cout << "Borrower ID: " << borrowerID << endl;
    cout << "br = l.getBorrower(borrowerID)" << endl;
    br = l.getBorrower(borrowerID);
    cout << "Expected borrower ID and name:" << endl;
    cout << "\t" << borrowerID << ", " << borrowerName << endl;
    cout << "Actual borrower ID and name:" << endl;
    cout << "\t" << br->getId() << ", " << br->getName() <<  endl;

    cout << "Calling withdraw function:" << endl;
    cout << "l.withdrawBook(BorrowerInformation * B1, string title, Date todaysDate);" << endl;
    l.withdrawBook(br, bookTitle, today);

    // Checking status of withdrawn book
    cout << "Checking status of withdrawn book:" << endl;
    cout << *b << endl;
    cout << "==========================" << endl;
    cout << endl;

    // Checking borrower for withdrawn book
    cout << "Checking borrower for withdrawn book:" << endl;
    cout << *br << endl;
    cout << endl;

    // Testing returnbook function
    cout << "Testing returnbook function:" << endl;
    cout << "l.returnBook(br, bookTitle, today);" << endl;
    l.returnBook(br, bookTitle, today);

    // Checking status of returned book
    cout << "Checking status of withdrawn book:" << endl;
    cout << *b << endl;
    cout << "==========================" << endl;
    cout << endl;

    // Checking borrower for returned book
    cout << "Checking borrower for withdrawn book:" << endl;
    cout << *br << endl;
    cout << endl;

   return 0;
}