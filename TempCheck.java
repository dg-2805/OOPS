/*Create two user defined exceptions viz. TooHot and TooCold. Write a Java program and throw TooHot 
if the temperature exceeds 40 degrees and throw TooCold if the temperature be less than 20 degrees.*/

#CODE
import java.util.Scanner;
class TooHot extends Exception {
    public TooHot(String message) {
        super(message);
    }
}
class TooCold extends Exception {
    public TooCold(String message) {
        super(message);
    }
}
class Temperature {
    public void checkTemperature(int temperature) throws TooHot, TooCold {
        if (temperature > 40) {
            throw new TooHot("Temperature is too hot: " + temperature + " degrees.");
        } else if (temperature < 20) {
            throw new TooCold("Temperature is too cold: " + temperature + " degrees.");
        } else {
            System.out.println("Temperature is normal: " + temperature + " degrees.");
        }
    }
}
public class TempCheck {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the temperature: ");
        int temperature = scanner.nextInt();
        Temperature temp = new Temperature();
        try {
            temp.checkTemperature(temperature);
        } catch (TooHot | TooCold e) {
            System.out.println(e.getMessage());
        } finally {
            scanner.close();
        }
    }
}

/* 
#OUTPUT
javac TempCheck.java 

$ java TempCheck
Enter the temperature: 34
Temperature is normal: 34 degrees.

$ java TempCheck
Enter the temperature: 65
Temperature is too hot: 65 degrees.

$ java TempCheck
Enter the temperature: 12
Temperature is too cold: 12 degrees. */
