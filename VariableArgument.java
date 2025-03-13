/*Write a program that demonstrates method average, which receives a variable length
sequence of doubles. public static double average(double ... numbers ).
Java treats the variable-length argument list as an array whose elements are all of the same
type. The method body can manipulate the parameter numbers as an array of doubles. Use for
loop to walk through the array and calculate the total of the doubles in the array. Use
numbers.length to obtain the size of the numbers array. Further change for loop to enhanced
for loop like for (double num : numbers)*/

public class VariableArgument {
    public static double average(double... numbers) {
        if (numbers.length == 0) return 0;
        double total = 0;
        
        // Using regular for loop
        /*for (int i = 0; i < numbers.length; i++) {
            total += numbers[i];
        }*/
        
        // Using enhanced for loop
        for (double num : numbers) {
            total += num;
        }
        
        
        return total / numbers.length;
    }

    public static void main(String[] args) {
        System.out.printf("Average of 10.5, 20.5, 30.5: %.1f%n", average(10.5, 20.5, 30.5));
        System.out.printf("Average of 5.0, 15.0, 25.0, 35.0: %.1f%n", average(5.0, 15.0, 25.0, 35.0));
        System.out.printf("Average of 42.0: %.1f%n", average(42.0));
    }
}

/*OUTPUT
$ javac VariableArgument.java

$ java VariableArgument
  
Average of 10.5, 20.5, 30.5: 20.5
Average of 5.0, 15.0, 25.0, 35.0: 20.0
Average of 42.0: 42.0
*/
