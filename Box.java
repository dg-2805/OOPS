/*Create a class called “Box” which contains three variables – width, height and length. Set the
values of the variables using constructor overloading as follows.
 Box(); //Default
 Box(int);// Parameterized for making cube
 Box(int, int, int); // Parameterized
 Box(Box); //Passing Object to Constructor (Copy Constructor)
The class has method “volume” which returns the volume of the box. In main method create
objects using each constructor and call the volume function to print the volume.
Write a method called “equals” in the “Box” class. “equals” method has only one parameter of
type Box. Use this function to check whether two boxes are identical or not.*/

class Box {
    private int width, height, length;

    // Default constructor
    public Box() {
        this.width = this.height = this.length = 1;
    }

    // Constructor for cube
    public Box(int side) {
        this.width = this.height = this.length = side;
    }

    // Parameterized constructor
    public Box(int width, int height, int length) {
        this.width = width;
        this.height = height;
        this.length = length;
    }

    // Copy constructor
    public Box(Box other) {
        this.width = other.width;
        this.height = other.height;
        this.length = other.length;
    }

    // Method to calculate volume
    public int volume() {
        return width * height * length;
    }

    // Equals method to compare two boxes
    public boolean equals(Box other) {
        return this.width == other.width && this.height == other.height && this.length == other.length;
    }

    public static void main(String[] args) {
        Box defaultBox = new Box();
        Box cube = new Box(3);
        Box rectangularBox = new Box(2, 4, 6);
        Box copiedBox = new Box(rectangularBox);

        System.out.println("Volume of default box: " + defaultBox.volume());
        System.out.println("Volume of cube: " + cube.volume());
        System.out.println("Volume of rectangular box: " + rectangularBox.volume());
        System.out.println("Volume of copied box: " + copiedBox.volume());

        System.out.println("Rectangular box and copied box are identical: " + rectangularBox.equals(copiedBox));
        System.out.println("Cube and rectangular box are identical: " + cube.equals(rectangularBox));
    }
}

/*OUTPUT
 javac Box.java

$ java Box

Volume of default box: 1
Volume of cube: 27
Volume of rectangular box: 48
Volume of copied box: 48
Rectangular box and copied box are identical: true
Cube and rectangular box are identical: false
*/
