#include "../BookInformation.h"

using namespace std;

int main()
{
    cout << "Calling general constructor:\n" << endl;
    cout << "BookInformation b(\"Harry Potter\", \"J.K. Rowling\", \"Fantasy\", \"Random House\", 115);" << endl;
    BookInformation b("Harry Potter", "J.K. Rowling", "Fantasy", "Random House", 115);

    // Testing getters
    cout << "Testing getters:\n" << endl;

    cout << "b.getTitle()" << endl;
    cout << "\t" << b.getTitle() << endl;
    cout << "b.getAuthor()" << endl;
    cout << "\t" << b.getAuthor() << endl;
    cout << "b.getSubject()" << endl;
    cout << "\t" << b.getSubject() << endl;

    cout << "b.getPublisher()" << endl;
    cout << "\t" << b.getPublisher() << endl;

    cout << "b.getPublishingDate()" << endl;
    cout << "\t" << b.getPublishingDate() << endl;

    cout << "b.getDueDate()" << endl;
    cout << "\t" << b.getDueDate() << endl;

    cout << "b.getLocation()" << endl;
    cout << "\t" << b.getLocation() << endl;
    cout << "b.getStatus()" << endl;
    cout << "\t" << b.getStatus() << endl;
    cout << "b.getCirculationPeriod()" << endl;
    cout << "\t" << b.getCirculationPeriod() << endl;
    cout << "b.getID()" << endl;
    cout << "\t" << b.getID() << endl;

    cout << "b.getCostOfBook()" << endl;
    cout << "\t" << b.getCostOfBook() << endl;
    cout << "b.getFinePerDayOverdue()" << endl;
    cout << "\t" << b.getFinePerDayOverdue() << endl;

    // Testing setters

    cout << "\nTesting b.setters:\n" << endl;

    cout << "setTitle(\"The Hobbit\");" << endl;
    b.setTitle("The Hobbit");
    cout << "\t" << b.getTitle() << endl;
    
    cout << "setAuthor(\"J.R.R. Tolkien\");" << endl;
    b.setAuthor("J.R.R. Tolkien");
    cout << "\t" << b.getAuthor() << endl;



    cout << "setSubject(\"Fantasy\");" << endl;
    b.setSubject("Fantasy");
    cout << "\t" << b.getSubject() << endl;

    cout << "setID(800);" << endl;
    b.setID(800);
    cout << "\t" << b.getID() << endl;

    cout << "setPublisher(\"Penguin Classics\");" << endl;
    b.setPublisher("Penguin Classics");
    cout << "\t" << b.getPublisher() << endl;

    cout << "setPublishingDate(Date (4,5,16));" << endl;
    b.setPublishingDate(Date (4,5,16));
    cout << "\t" << b.getPublishingDate() << endl;

    cout << "setDueDate(Date (4/15/19));" << endl;
    b.setDueDate(Date (4,15,19));
    cout << "\t" << b.getDueDate() << endl;

    cout << "setLocation(3);" << endl;
    b.setLocation(3);
    cout << "\t" << b.getLocation() << endl;

    cout << "setStatus(AVAILABLE);" << endl;
    b.setStatus(AVAILABLE);
    cout << "\t" << b.getStatus() << endl;

    cout << "setCirculationPeriod(7);" << endl;
    b.setCirculationPeriod(7);
    cout << "\t" << b.getCirculationPeriod() << endl;

    cout << "setCostOfBook(10.95);" << endl;
    b.setCostOfBook(10.95);
    cout << "\t" << b.getCostOfBook() << endl;

    cout << "setFinePerDayOverdue(5.00);" << endl;
    b.setFinePerDayOverdue(5.00);
    cout << "\t" << b.getFinePerDayOverdue() << endl;

    cout << "setFinePerDayOverdue();" << endl;
    b.setFinePerDayOverdue();
    cout << "\t" << b.getFinePerDayOverdue() << endl;

    return 0;
}