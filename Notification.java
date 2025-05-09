/*Create a Java program that simulates a Notification System. You should define an interface called Notifier with a method notifyUser(). 
Write a class NotificationManager that includes a method sendNotification(Notifier notifier), which calls the notifyUser() method. 
In the main method, use anonymous inner classes to send different types of notifications: 
● One for Email Notification 
● One for SMS Notification 
● One for Push Notification */

#CODE
interface Notifier{
    void notifyUser();
}
public class Notification {
    public void senNotif(Notifier notif){
        notif.notifyUser();
    }
    public static void main(String [] args){
        Notification n=new Notification();
        n.senNotif(new Notifier (){
            public void notifyUser(){
                System.out.println("Email Notification Sent");
            }
        });
        n.senNotif(new Notifier (){
            public void notifyUser(){
                System.out.println("SMS Notification Sent");
            }
        });
        n.senNotif(new Notifier (){
            public void notifyUser(){
                System.out.println("PushNotification Sent");
            }
        });
        
    }   
}

/* #OUTPUT

javac Notification.java 

$ java Notification
Email Notification Sent
SMS Notification Sent
PushNotification Sent */
