/*Write a program that creates three task and three threads to run them. 
● The first task prints the letter a 100 times. 
● The second task prints the letter b 100 times. 
● The third task prints the integers 1 through 100.*/
#CODE

class A implements Runnable{
    public void run(){
        for(int i=0;i<100;i++){
            System.out.print("a");
        }
    }
}
class B implements Runnable{
    public void run(){
        for(int i=0;i<100;i++){
            System.out.print("b");
        }
    }
}
class C implements Runnable{
    public void run(){
        for(int i=0;i<100;i++){
            System.out.print(i);
        }
    }
}
public class MultiThread {
    public static void main(String[] args) {
        Thread t1 = new Thread(new A());
        Thread t2 = new Thread( new B());
        Thread t3 = new Thread( new C());
        t1.start();
        t2.start();
        t3.start();
    }
}

/*OUTPUT
$ javac MultiThread.java 

$ java MultiThread
bbbbbbbbbbbbb0aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa1bbbbbbbbbbb
bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb23aaaaaaaa4bbbbbbbbbbb5678910111213141516171819202122
2324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081
828384858687888990919293949596979899
*/
