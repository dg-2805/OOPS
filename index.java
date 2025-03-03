public class index {
    public static void main(String[] args) {
        if (args.length != 3) {
            System.out.println("Please provide exactly 3 command line arguments.");
            return;
        }

        try {
            int size = Integer.parseInt(args[0]);
            int start = Integer.parseInt(args[1]);
            int increment = Integer.parseInt(args[2]);

            if (size != 5) {
                System.out.println("The size of the array must be 5.");
                return;
            }
            System.out.println("Index\tValue");

            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = start + (i * increment);
            }

            for (int i = 0; i < size; i++) {
                System.out.printf("%d\t%d%n", i, array[i]);
            }
        } catch (NumberFormatException e) {
            System.out.println("Please provide valid integers as command line arguments.");
        }
    }
}



/*SAMPLE OUTPUT

$ javac index.java

$ java index 5 0 4
Index   Value
0       0
1       4
2       8
3       12
4       16


  */
