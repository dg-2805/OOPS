/*Create a class MyClass which has member variable x of integer type and have the following
constructors
MyClass( ) // Default
MyClass(int)// Parameterized
MyClass(MyClass &amp;amp;) // Copy
destructor ~ MyClass()
and member function to display value of x. Create global objects, objects local to a function, local to
main and object copy of another objects. Write suitable code to show how multiple no of objects are
created and destroyed in the program. Display appropriate message which constructor is called using
object creation. Write down observations the order the objects are created and destroyed. Modify
program by using the concept of pointer to objects. Create dynamic object using new operator and use
delete for destruction for the class Myclass.*/
#include <iostream>

using namespace std;

class MyClass {
    int x;

public:
    // Default Constructor
    MyClass() {
        x = 0;
        cout << "Default Constructor called. x = " << x << endl;
    }

    // Parameterized Constructor
    MyClass(int val) {
        x = val;
        cout << "Parameterized Constructor called. x = " << x << endl;
    }

    // Copy Constructor
    MyClass(const MyClass &obj) {
        x = obj.x;
        cout << "Copy Constructor called. x = " << x << endl;
    }

    // Destructor
    ~MyClass() {
        cout << "Destructor called for x = " << x << endl;
    }

    // Display function
    void display() {
        cout << "Value of x: " << x << endl;
    }
};

// Global object (created before main() runs, destroyed after main() ends)
MyClass globalObj(100);

void functionScope() {
    cout << "\nEntering functionScope()" << endl;
    MyClass localFuncObj(50); // Local object inside function
    cout << "Exiting functionScope()\n" << endl;
} // localFuncObj gets destroyed here

int main() {
    cout << "\nEntering main()" << endl;

    // Local object in main()
    MyClass obj1;  
    MyClass obj2(20); 
    MyClass obj3 = obj2; // Copy constructor

    // Creating dynamic object using new
    cout << "\nCreating dynamic object...\n";
    MyClass *dynObj = new MyClass(30);

    // Display dynamic object value
    dynObj->display();

    // Calling function that creates an object locally
    functionScope();

    // Deleting dynamic object
    cout << "\nDeleting dynamic object...\n";
    delete dynObj;

    cout << "\nExiting main()\n" << endl;
    return 0;
} // All local objects in main() are destroyed here



/*OUTPUT
Parameterized Constructor called. x = 100

Entering main()
Default Constructor called. x = 0
Parameterized Constructor called. x = 20
Copy Constructor called. x = 20

Creating dynamic object...
Parameterized Constructor called. x = 30
Value of x: 30

Entering functionScope()
Parameterized Constructor called. x = 50
Exiting functionScope()

Destructor called for x = 50

Deleting dynamic object...
Destructor called for x = 30

Exiting main()

Destructor called for x = 20
Destructor called for x = 0
Destructor called for x = 100

*/
