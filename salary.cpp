/*Write a program in C++ to implement two classes Employee and Boss. Boss has the capability to
increase the salary (Employee has a variable named salary) of the Employee. Use concept of FRIEND
class. */

CODE
#include <iostream>
using namespace std;

class Employee {
    double salary;

public:
    void setSalary(double s) {
        salary = s;
    }

    void showSalary() {
        cout << "Employee Salary: Rs. " << salary << endl;
    }

    friend class Boss;
};

class Boss {
public:
    void increaseSalary(Employee &e, double amount) {
        e.salary += amount;
    }
};

int main() {
    Employee emp;
    Boss boss;
    double salary, increment;

    cout << "Enter employee's initial salary: ";
    cin >> salary;
    emp.setSalary(salary);

    cout << "Enter increment amount: ";
    cin >> increment;

    cout << "\nBefore Salary Increment:\n";
    emp.showSalary();

    boss.increaseSalary(emp, increment);

    cout << "\nAfter Salary Increment:\n";
    emp.showSalary();

    return 0;
}

/*OUTPUT
Enter employee's initial salary: 50000
Enter increment amount: 4290

Before Salary Increment:
Employee Salary: Rs. 50000

After Salary Increment:
Employee Salary: Rs. 54290*/
