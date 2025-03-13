/*Q1. Create a class MyClass which has member variable x of integer type and have the following
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
public:
    int x;

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
    MyClass(MyClass &obj) {
        x = obj.x;
        cout << "Copy Constructor called. x = " << x << endl;
    }

    // Destructor
    ~MyClass() {
        cout << "Destructor called. x = " << x << endl;
    }

    // Member function to display value of x
    void display() {
        cout << "Value of x: " << x << endl;
    }
};

// Global object
MyClass globalObj(10);

// Function to demonstrate local objects
void demoFunction() {
    cout << "\nInside demoFunction():" << endl;
    MyClass localFuncObj(20); // Local object in function
    localFuncObj.display();
    cout << "Exiting demoFunction()." << endl;
}

int main() {
    cout << "\nInside main():" << endl;

    // Local object in main
    MyClass localMainObj(30);
    localMainObj.display();

    // Object copy of another object
    MyClass copiedObj(localMainObj);
    copiedObj.display();

    // Call function to demonstrate local objects
    demoFunction();

    // Dynamic object creation using new
    cout << "\nCreating dynamic object:" << endl;
    MyClass *dynamicObj = new MyClass(40);
    dynamicObj->display();

    // Destroy dynamic object using delete
    cout << "Deleting dynamic object:" << endl;
    delete dynamicObj;

    cout << "\nExiting main()." << endl;
    return 0;
}


/*OUTPUT
Parameterized Constructor called. x = 10

Inside main():
Parameterized Constructor called. x = 30
Value of x: 30
Copy Constructor called. x = 30
Value of x: 30

Inside demoFunction():
Parameterized Constructor called. x = 20
Value of x: 20
Exiting demoFunction().
Destructor called. x = 20

Creating dynamic object:
Parameterized Constructor called. x = 40
Value of x: 40
Deleting dynamic object:
Destructor called. x = 40

Exiting main().
Destructor called. x = 30
Destructor called. x = 30
Destructor called. x = 10
*/
