/*Create an interface “College” containing attributes CollegeName and CollegeCode. It also
has abstract method display(). Create a class “Department” containing attributes deptName,
DeptHead. The class contains methods for accepting and displaying member variables . Then
write “Student” class extending “Department” class and implementing “College” interface. This
class contains attributes studentName, regNo, and avgMarks. Write a driver class to test the
“Student” class. Print all the details of the student.*/

interface College {
    String CollegeName = "HITK";
    String CollegeCode = "126";
    void display();
}

class Department {
    private String deptName;
    private String DeptHead;

    public Department(String deptName, String DeptHead) {
        this.deptName = deptName;
        this.DeptHead = DeptHead;
    }

    public void displayDepartment() {
        System.out.println("Department Name: " + deptName);
        System.out.println("Department Head: " + DeptHead);
    }
}

class Student extends Department implements College {
    private String studentName;
    private int regNo;
    private double avgMarks;

    public Student(String deptName, String DeptHead, String studentName, int regNo, double avgMarks) {
        super(deptName, DeptHead);
        this.studentName = studentName;
        this.regNo = regNo;
        this.avgMarks = avgMarks;
    }

    public void display() {
        System.out.println("College Name: " + CollegeName);
        System.out.println("College Code: " + CollegeCode);
        displayDepartment();
        System.out.println("Student Name: " + studentName);
        System.out.println("Registration Number: " + regNo);
        System.out.println("Average Marks: " + avgMarks);
    }
}

public class TestStudent {
    public static void main(String[] args) {
        Student student1 = new Student("CSE", "SM", "DG", 2351100, 91.5);
        student1.display();
    }
}

/*OUTPUT

$ javac TestStudent.java

$ java TestStudent
College Name: HITK
College Code: 126
Department Name: CSE
Department Head: SM
Student Name: DG
Registration Number: 2351100
Average Marks: 91.5
*/
