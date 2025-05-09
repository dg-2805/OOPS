/**
 * This class Calculator contains a static inner class Operations.
 * Operations include:
 * - add(int a, int b)
 * - subtract(int a, int b)
 * - multiply(int a, int b)
 * - divide(int a, int b)
 * 
 * The main method demonstrates the use of Calculator.Operations
 * without creating an instance of the outer class.
 */

#CODE
public class Calculator {
    static class Operations {
        public static int add(int a, int b) {
            return a + b;
        }

        public static int subtract(int a, int b) {
            return a - b;
        }

        public static int multiply(int a, int b) {
            return a * b;
        }

        public static double divide(int a, int b) {
            if (b == 0) {
                throw new ArithmeticException("Cannot divide by zero");
            }
            return (double) a / b;
        }
    }

    public static void main(String[] args) {
        System.out.println("Addition: " + Operations.add(5, 3));
        System.out.println("Subtraction: " + Operations.subtract(5, 3));
        System.out.println("Multiplication: " + Operations.multiply(5, 3));
        System.out.println("Division: " + Operations.divide(5, 3));
    }
    
}

/* #OUTPUT
$ javac Calculator.java 

$ java Calculator
Addition: 8
Subtraction: 2
Multiplication: 15
Division: 1.6666666666666667 */
