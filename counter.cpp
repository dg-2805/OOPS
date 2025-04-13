/*Create a class named as COUNTER to keep track of a count. Write two different operator function to Ingrement C1 by prefix increment operator and decrement 02 by postfix decrement operator where C1, C2 are two objects of the class COUNTER.*/

#include <iostream>
using namespace std;

class Counter {
private:
    int data;

public:
    Counter() {
        this->data = 0;
    }

    // Prefix increment operator (++counter)
    Counter operator++() {
        ++data;
        return *this;
    }

    // Postfix decrement operator (counter--)
    Counter operator--(int) {
        Counter temp = *this;
        data--;
        return temp;
    }

    friend ostream& operator<<(ostream& out, const Counter& c);
    friend istream& operator>>(istream& in, Counter& c);
};

ostream& operator<<(ostream& out, const Counter& c) {
    out << "Counter value: " << c.data;
    return out;
}

istream& operator>>(istream& in, Counter& c) {
    cout << "Enter counter value: ";
    in >> c.data;
    return in;
}

int main() {
    Counter c1, c2, c3;
    
    // Test prefix increment
    cin >> c1;
    cout << "Before increment: " << c1 << endl;
    ++c1;
    cout << "After prefix increment: " << c1 << endl;
    
    // Test postfix decrement
    cin >> c2;
    cout << "Before decrement: " << c2 << endl;
    c3 = c2--;  // c3 gets the old value, c2 is decremented
    cout << "After postfix decrement:" << endl;
    cout << "c2 (decremented): " << c2 << endl;
    cout << "c3 (original value): " << c3 << endl;
    return 0;
}

/* OUTPUT
Enter counter value: 15
Before increment: Counter value: 15
After prefix increment: Counter value: 16
Enter counter value: 7
Before decrement: Counter value: 7
After postfix decrement:
c2 (decremented): Counter value: 6
c3 (original value): Counter value: 7
*/
