/*2.  Create a Java program to model a simple Library system where each Library has multiple 
Books. Use a non-static inner class Book inside the outer class Library. 
-The Library class should have a name. 
-The Book class should store title and author of the book. 
-Add a method in Library to print details of all books. 
-Demonstrate adding books to a library and printing them.  */

// #CODE
import java.util.ArrayList;

public class Library {
    String name;
    ArrayList<Book> books = new ArrayList<>();

    public Library(String name) {
        this.name = name;
    }

    class Book {
        String title, author;

        Book(String title, String author) {
            this.title = title;
            this.author = author;
        }
    }

    public void addBook(String title, String author) {
        books.add(new Book(title, author));
    }

    public void printBooks() {
        System.out.println("Library: " + name);
        for (Book b : books) {
            System.out.println("Title: " + b.title + ", Author: " + b.author);
        }
    }

    public static void main(String[] args) {
        Library lib = new Library("College Library");
        lib.addBook("To Kill a Mocking Bird", "Harper Lee");
        lib.addBook("The Tides of Memory", "Sidney Sheldon");
        lib.addBook("The Alchemist", "Paulo Coelho");
        lib.addBook("The Da Vinci Code", "Dan Brown");
        lib.addBook("The Metamorphosis", "Franz Kafka");
        lib.printBooks();
    }
}
/*OUTPUT

$ javac Library.java 

$ java Library
Library: College Library
Title: To Kill a Mocking Bird, Author: Harper Lee
Title: The Tides of Memory, Author: Sidney Sheldon
Title: The Alchemist, Author: Paulo Coelho
Title: The Da Vinci Code, Author: Dan Brown
Title: The Metamorphosis, Author: Franz Kafka
*/
