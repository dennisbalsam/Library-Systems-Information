#include <string>
#include <vector>
#include <iostream>
#include "../src/BookInformation.h"
#include "../src/BorrowerInformation.h"

using namespace std;

int main()
{
    // default construction
    BorrowerInformation b1;

    // test default values
    cout << b1.getName() << endl;
    cout << b1.getAddress() << endl;
    cout << b1.getPhoneNumber() << endl;
    cout << b1.getId() << endl;
    cout << b1.getFeeBalance() << endl;

    return 0;
}
