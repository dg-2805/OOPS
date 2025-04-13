/*1. WAP in C++ to create a class MyComplex which has the two member variables (both of type "double"). The class should have the following features: real and imaginary are initialized to default values 0.0 and 0.0 when no parameters are supplied, or,
b) real and imagor are initialized to the supplied parameter values, or
c) they derive the invalues from the supplied object of type MyComplex
In addition to the above features, the following should be also supported:
d) Two MyComplex objects should use the "+","" and "*" operators operators to perform addition,subtraction and multiplication according to standard rules for Complex numbers. Use concept of operator overloading .
e) overload>> and << operators to accept and display members with objects
*/

#include <iostream>
using namespace std;

class MyComplex {
private:
    double real;
    double img;

public:
    // Default constructor (initializes to 0.0 + 0.0i)
    MyComplex() {
        this->real = 0.0;
        this->img = 0.0;
    }

    // Parameterized constructor (initializes with given values)
    MyComplex(double real, double img) {
        this->real = real;
        this->img = img;
    }

    // Copy constructor (derives values from another MyComplex object)
    MyComplex(const MyComplex &other) {
        this->real = other.real;
        this->img = other.img;
    }

    // Addition operator overloading (+)
    MyComplex operator+(const MyComplex &other) {
        return MyComplex(this->real + other.real, this->img + other.img);
    }

    // Subtraction operator overloading (-)
    MyComplex operator-(const MyComplex &other) {
        return MyComplex(this->real - other.real, this->img - other.img);
    }

    // Multiplication operator overloading (*)
    MyComplex operator*(const MyComplex &other) {
        double x = this->real * other.real - this->img * other.img;
        double y = this->real * other.img + this->img * other.real;
        return MyComplex(x, y);
    }

    // Friend functions for input and output
    friend ostream& operator<<(ostream& out, const MyComplex& c);
    friend istream& operator>>(istream& in, MyComplex& c);
};

// Overloaded << operator for output
ostream& operator<<(ostream& out, const MyComplex& c) {
    out << c.real;
    if (c.img > 0) {
        out << "+" << c.img << "i";
    } else if (c.img < 0) {
        out << "-" << -c.img << "i";
    }
    return out;
}

// Overloaded >> operator for input
istream& operator>>(istream& in, MyComplex& c) {
    in >> c.real >> c.img;
    return in;
}

int main() {
    MyComplex c1, c2, c3, c4, c5;

    cout << "Enter C1 (real and imaginary parts separated by space): ";
    cin >> c1;
    cout << "Enter C2 (real and imaginary parts separated by space): ";
    cin >> c2;

    c3 = c1 + c2;
    cout << "C3 (C1 + C2) = " << c3 << endl;

    c4 = c1 - c2;
    cout << "C4 (C1 - C2) = " << c4 << endl;

    c5 = c1 * c2;
    cout << "C5 (C1 * C2) = " << c5 << endl;

    return 0;
}


/* OUTPUT

Enter C1 (real and imaginary parts separated by space): 1 2
Enter C2 (real and imaginary parts separated by space): -3 5
C3 (C1 + C2) = -2+7i
C4 (C1 - C2) = 4-3i
C5 (C1 * C2) = -13-1i

*/
