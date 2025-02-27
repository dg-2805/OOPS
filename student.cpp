/* Write a program in C++ to create a structure Student which has variables student_ name of data type
string, roll_no as integer and branch_ name as character array, marks of three subjects m1, m2, m3,
total_marks and two functions void accept() and void display() to accept and display student’s
information. Using concept of array of structure accept 3 students’ data and display the information in
proper format by using setw() function.*/


#include <iostream>
#include <iomanip> // For setw() function
#include <string>  // For string data type
using namespace std;

// Define the Student structure
struct Student {
    string student_name;
    int roll_no;
    char branch_name[50];
    float m1, m2, m3;
    float total_marks;

    // Function to accept student details
    void accept() {
        cout << "Enter Student Name: ";
        getline(cin, student_name); // Use getline to handle spaces in names
        cout << "Enter Roll No: ";
        cin >> roll_no;
        cin.ignore(); // Clear the input buffer
        cout << "Enter Branch Name: ";
        cin.getline(branch_name, 50);
        cout << "Enter Marks for Subject 1: ";
        cin >> m1;
        cout << "Enter Marks for Subject 2: ";
        cin >> m2;
        cout << "Enter Marks for Subject 3: ";
        cin >> m3;
        cin.ignore(); // Clear the input buffer
        total_marks = m1 + m2 + m3; // Calculate total marks
    }

    // Function to display student details
    void display() {
        cout << setw(15) << student_name << setw(10) << roll_no << setw(15) << branch_name
             << setw(10) << m1 << setw(10) << m2 << setw(10) << m3 << setw(15) << total_marks << endl;
    }
};

int main() {
    const int num_students = 3;
    Student students[num_students];

    // Accept details for 3 students
    for (int i = 0; i < num_students; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        students[i].accept();
    }

    // Display details in a formatted table
    cout << "\nStudent Details:\n";
    cout << setw(15) << "Name" << setw(10) << "Roll No" << setw(15) << "Branch"
         << setw(10) << "M1" << setw(10) << "M2" << setw(10) << "M3" << setw(15) << "Total Marks" << endl;
    for (int i = 0; i < num_students; i++) {
        students[i].display();
    }

    return 0;
}

/*SAMPLE OUTPUT:

Enter details for Student 1:
Enter Student Name: John Doe
Enter Roll No: 101
Enter Branch Name: Computer Science
Enter Marks for Subject 1: 85
Enter Marks for Subject 2: 90
Enter Marks for Subject 3: 78

Enter details for Student 2:
Enter Student Name: Jane Smith
Enter Roll No: 102
Enter Branch Name: Electrical Engineering
Enter Marks for Subject 1: 88
Enter Marks for Subject 2: 92
Enter Marks for Subject 3: 85

Enter details for Student 3:
Enter Student Name: Alice Johnson
Enter Roll No: 103
Enter Branch Name: Mechanical Engineering
Enter Marks for Subject 1: 75
Enter Marks for Subject 2: 80
Enter Marks for Subject 3: 82

Student Details:
           Name   Roll No          Branch        M1        M2        M3    Total Marks
      John Doe      101  Computer Science        85        90        78           253
    Jane Smith      102  Electrical Engineering 88        92        85           265
 Alice Johnson      103  Mechanical Engineering 75        80        82           237

*/