/*Create a class named “Student” having protected instance variables Roll_number,
Student_Name and class variable College_Name having values &quot;HITK&quot;. Use constructor to
initialize data members. It contains method “showdata()” to display student&#39;s details. Inherit the
Student class and create subclass named “Exam ” having private instance variable marks of
three subjects . Use constructor to initialize data members .It contains the method
“showresult()” which will display student information along with average mark of three subjects.
Write a program in java to test the “Exam” class and to display all the details of Student.*/

class Student {
    protected int Roll_number;
    protected String Student_Name;
    protected static String College_Name = "HITK";

    public Student(int Roll_number, String Student_Name) {
        this.Roll_number = Roll_number;
        this.Student_Name = Student_Name;
    }

    public void showdata() {
        System.out.println("Roll Number: " + Roll_number);
        System.out.println("Student Name: " + Student_Name);
        System.out.println("College Name: " + College_Name);
    }
}

class Exam extends Student {
    private int m1, m2, m3;

    public Exam(int Roll_number, String Student_Name, int m1, int m2, int m3) {
        super(Roll_number, Student_Name);
        this.m1 = m1;
        this.m2 = m2;
        this.m3 = m3;
    }

    public void showresult() {
        showdata();
        double average = (m1 + m2 + m3) / 3.0;
        System.out.println("Average Marks: " + average);
    }
}

public class TestExam {
    public static void main(String[] args) {
        Exam student1 = new Exam(100, "DG", 85, 92, 89);
        student1.showresult();
    }
}

/* OUTPUT

$ javac TestExam.java

$ java TestExam
Roll Number: 100
Student Name: DG
College Name: HITK
Average Marks: 88.66666666666667

*/
