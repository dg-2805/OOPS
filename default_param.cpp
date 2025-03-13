/*Write a function that normally takes one argument, the address of a string, and prints that string
once. However, if a second, type int, argument is provided and is nonzero, the function should print the
string a number of times equal to the number of times equal to the value of the second argument. Use
the function in a simple program that demonstrates how the function works.*/

#include <iostream>
using namespace std;

// Function to print a string once or multiple times
void printString(const char* str, int times = 1) {
    if (times <= 0) times = 1; // Ensure at least one print
    
    for (int i = 0; i < times; i++) {
        cout << str << endl;
    }
}

int main() {
    // Taking user input
    string inputString;
    int repeatTimes;
    
    cout << "Enter a string: ";
    getline(cin, inputString);
    
    cout << "Enter number of times to print (default is 1): ";
    cin >> repeatTimes;
    
    // Demonstrating the function with user input
    printString(inputString.c_str(), repeatTimes);
    
    return 0;
}

/*OUTPUT
Enter a string: Wild West
Enter number of times to print (default is 1): 5
Wild West
Wild West
Wild West
Wild West
Wild West

Enter a string: Checking
Enter number of times to print (default is 1): 0
Checking

Enter a string: India wins !!
Enter number of times to print (default is 1): -2
India wins !!
*/
