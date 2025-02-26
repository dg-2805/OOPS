/* Write a program in C++ to create a structure Student which has variables student_ name of data type
string, roll_no as integer and branch_ name as character array, marks of three subjects m1, m2, m3,
total_marks and two functions void accept() and void display() to accept and display student’s
information. Using concept of array of structure accept 3 students’ data and display the information in
proper format by using setw() function.*/
#include <string>

using namespace std;

struct student {
    string std_name;
    int roll;
    char branch[25];
    int m1;
    int m2;
    int m3;
    int total;

    void accept();
    void display();
};

void student::accept() {
    cout << "Enter name: ";
    getline(cin, std_name);
    cout << "Enter roll no: ";
    cin >> roll;
    cout << "Enter branch: ";
    cin >> branch;
    cout << "Enter Maths: ";
    cin >> m1;
    cout << "Enter Physics: ";
    cin >> m2;
    cout << "Enter Chemistry: ";
    cin >> m3;
    total = m1 + m2 + m3;
    getchar(); // To consume the newline character left by cin
}

void student::display() {
    cout << std_name << endl
         << roll << endl
         << branch << endl
         << m1 << endl
         << m2 << endl
         << m3 << endl
         << total << endl;
}

int main() {
    student st[3];
    for (int i = 0; i < 3; i++) {
        st[i].accept();
        st[i].display();
    }
    return 0;
}
/*
./prime
Enter name: Shreya
Enter roll no: 101
Enter branch: CSE
Enter Maths: 75
Enter Physics: 80
Enter Chemistry: 90  
Shreya
101
CSE
75
80
90
245
  */
