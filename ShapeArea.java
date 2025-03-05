/*2. Writ a program to implement function overloading with the following specification:
a. Area(int) :- to calculate area of square
b. Area(int,int) :- to calculate area of rectangle
c. Area(double) :- to calculate area of circle */

import java.util.Scanner;

public class ShapeArea {

    // Area of square
    static double Area(int side) {
        return side * side;
    }

    // Area of rectangle
    static double Area(int length, int width) {
        return length * width;
    }

    // Area of circle
    static double Area(double radius) {
        return Math.PI * radius * radius;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input for square
        System.out.print("Enter side of square: ");
        int side = sc.nextInt();
        System.out.println("Area of square (side = " + side + "): " + Area(side));

        // Input for rectangle
        System.out.print("Enter length of rectangle: ");
        int length = sc.nextInt();
        System.out.print("Enter width of rectangle: ");
        int width = sc.nextInt();
        System.out.println("Area of rectangle (length = " + length + ", width = " + width + "): " + Area(length, width));

        // Input for circle
        System.out.print("Enter radius of circle: ");
        double radius = sc.nextDouble();
        System.out.println("Area of circle (radius = " + radius + "): " + Area(radius));

        sc.close();
    }
}
/*
SAMPLE OUTPUT
$ javac ShapeArea.java

$ java ShapeArea
Enter side of square: 5
Area of square (side = 5): 25.0
Enter length of rectangle: 6
Enter width of rectangle: 7
Area of rectangle (length = 6, width = 7): 42.0
Enter radius of circle: 8
Area of circle (radius = 8.0): 201.06192982974676
*/
