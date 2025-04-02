/*Create an abstract class "Shape"; . The class "Shape"; has two abstract methods "Area"; and
"Perimeter". Declare classes Square,Rectangle, Circle as sub-classes of Shape. Using
the concept of dynamic Method Dispatch find out the surface area and perimeter of a square,
rectangle and circle.*/

abstract class Shape {
    abstract double Area();
    abstract double Perimeter();
}

class Square extends Shape {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    double Area() {
        return side * side;
    }

    double Perimeter() {
        return 4 * side;
    }
}

class Rectangle extends Shape {
    private double length, breadth;

    public Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    double Area() {
        return length * breadth;
    }

    double Perimeter() {
        return 2 * (length + breadth);
    }
}

class Circle extends Shape {
    private double radius;
    private static final double PI = 3.14159;

    public Circle(double radius) {
        this.radius = radius;
    }

    double Area() {
        return PI * radius * radius;
    }

    double Perimeter() {
        return 2 * PI * radius;
    }
}

public class TestShape {
    public static void main(String[] args) {
        Shape s1 = new Square(5);
        Shape s2 = new Rectangle(4, 6);
        Shape s3 = new Circle(3);

        System.out.println("Square - Area: " + s1.Area() + ", Perimeter: " + s1.Perimeter());
        System.out.println("Rectangle - Area: " + s2.Area() + ", Perimeter: " + s2.Perimeter());
        System.out.println("Circle - Area: " + s3.Area() + ", Perimeter: " + s3.Perimeter());
    }
}

/*OUTPUT

$ javac TestShape.java

$ java TestShape
Square - Area: 25.0, Perimeter: 20.0
Rectangle - Area: 24.0, Perimeter: 20.0
Circle - Area: 28.274309999999996, Perimeter: 18.849539999999998
*/
