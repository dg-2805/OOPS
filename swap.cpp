//Write a program in C++ to swap the private data members of two classes using FRIEND function

#include <iostream>
using namespace std;

class B; // Forward declaration

class A {
    int a;

public:
    void setData(int x) { a = x; }

    friend void swapData(A &objA, B &objB);

    void show() {
        cout << "A: " << a << endl;
    }
};

class B {
    int b;

public:
    void setData(int y) { b = y; }

    friend void swapData(A &objA, B &objB);

    void show() {
        cout << "B: " << b << endl;
    }
};

void swapData(A &objA, B &objB) {
    int temp = objA.a;
    objA.a = objB.b;
    objB.b = temp;
}

int main() {
    A objA;
    B objB;
    int x, y;

    cout << "Enter value for A: ";
    cin >> x;
    objA.setData(x);

    cout << "Enter value for B: ";
    cin >> y;
    objB.setData(y);

    cout << "\nBefore Swapping:\n";
    objA.show();
    objB.show();

    swapData(objA, objB);

    cout << "\nAfter Swapping:\n";
    objA.show();
    objB.show();

    return 0;
}

/*OUTPUT
Enter value for A: 51
Enter value for B: 2

Before Swapping:
A: 51
B: 2

After Swapping:
A: 2
B: 51
*/
