/*Consider a toll-booth at a bridge. Cars passing by the booth are expected to pay Rs. 10 in cash as toll.
Mostly they do but sometimes a car goes by without paying. The toll-booth keeps track of the number of
cars that have gone by, and the amount of cash collected. Model this toll-booth using a class called
tollBooth, having member data called totalCars (of type integer for total number of cars passed) and
totalCash (of type double for total amount of cash collected). Use a constructor to initialize both data
members to zero. A member function called nopayCar() increases the car count only, while another
member function payingCar() increases both the car count and the cash total. There is another member
function called display() shows the car count, the cash total, and the total number of non-paying cars.
Write a program to test this class using three menu options as follows:
1. The user enters 0 for each non-paying car.
2. The user enters 1 for each paying car.
3. The user enters 9 for displaying the total number of cars, the total cash collected, the total number of
non-paying cars, and then exit. */

#include <iostream>
using namespace std;

class TollBooth {
    int totalCars;
    double totalCash;

public:
    TollBooth() : totalCars(0), totalCash(0.0) {}

    void nopayCar() {
        totalCars++;
    }

    void payingCar() {
        totalCars++;
        totalCash += 10.0;
    }

    void display() {
        cout << "Total Cars: " << totalCars << endl;
        cout << "Total Cash Collected: Rs. " << totalCash << endl;
        cout << "Non-Paying Cars: " << (totalCars - totalCash / 10) << endl;
    }
};

int main() {
    TollBooth booth;
    int choice;
    
    cout << "Enter 0 for non-paying car, 1 for paying car, 9 to display and exit:\n";

    while (true) {
        cin >> choice;
        if (choice == 0)
            booth.nopayCar();
        else if (choice == 1)
            booth.payingCar();
        else if (choice == 9) {
            booth.display();
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

/* OUTPUT

Enter 0 for non-paying car, 1 for paying car, 9 to display and exit:
0 1 0 1 1 1 0
9
Total Cars: 7
Total Cash Collected: Rs. 40
Non-Paying Cars: 3
*/
