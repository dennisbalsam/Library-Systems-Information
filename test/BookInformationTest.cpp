#include "../src/BookInformation.h"

using namespace std;

int main()
{
    // BookInformation b("Harry Potter", "J.K. Rowling", "Fantasy", "Random House", 115);
    BookInformation b;

    cout << "Testing getters:" << endl;

    cout << "b.getTitle()" << endl;
    cout << b.getTitle() << endl;
    cout << "b.getAuthor()" << endl;
    cout << b.getAuthor() << endl;
    cout << "b.getSubject()" << endl;
    cout << b.getSubject() << endl;

    cout << "b.getPublisher()" << endl;
    cout << b.getPublisher() << endl;

    cout << "b.getPublishingDate()" << endl;
    cout << b.getPublishingDate() << endl;

    cout << "b.getDueDate()" << endl;
    cout << b.getDueDate() << endl;

    cout << "b.getLocation()" << endl;
    cout << b.getLocation() << endl;
    cout << "b.getStatus()" << endl;
    cout << b.getStatus() << endl;
    cout << "b.getCirculationPeriod()" << endl;
    cout << b.getCirculationPeriod() << endl;
    cout << "b.getID()" << endl;
    cout << b.getID() << endl;

    cout << "b.getCostOfBook()" << endl;
    cout << b.getCostOfBook() << endl;
    cout << "b.getFinePerDayOverdue()" << endl;
    cout << b.getFinePerDayOverdue() << endl;

    return 0;
}