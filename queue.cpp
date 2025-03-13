/*Create a class QUEUE to implement queue data structure with constructors &amp; destructors. Define
suitable member functions for insertion &amp; deletion of elements to &amp; from the queue. Write a program in
C++ to do this by clearly specifying the overflow &amp; underflow conditions.*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Maximum size of the queue

class QUEUE {
private:
    int arr[MAX_SIZE]; // Array to store queue elements
    int front, rear;   // Front and rear pointers

public:
    // Constructor
    QUEUE() {
        front = -1; // Initialize front and rear to -1 (empty queue)
        rear = -1;
        cout << "Queue initialized. Front = " << front << ", Rear = " << rear << endl;
    }

    // Destructor
    ~QUEUE() {
        cout << "Queue destroyed." << endl;
    }

    // Function to check if the queue is full (overflow condition)
    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    // Function to check if the queue is empty (underflow condition)
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Function to insert an element into the queue (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << ". Queue is full." << endl;
            return;
        }
        if (front == -1) { // If queue is empty, set front to 0
            front = 0;
        }
        rear++; // Increment rear
        arr[rear] = value; // Insert the element
        cout << "Enqueued " << value << " to the queue." << endl;
    }

    // Function to delete an element from the queue (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue. Queue is empty." << endl;
            return;
        }
        int value = arr[front]; // Get the element at the front
        front++; // Increment front
        cout << "Dequeued " << value << " from the queue." << endl;
        if (front > rear) { // Reset front and rear if the queue becomes empty
            front = -1;
            rear = -1;
        }
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    QUEUE q; // Create a queue object
    int choice, value;

    while (true) {
        cout << "\n--- QUEUE MENU ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Enqueue
                if (q.isFull()) {
                    cout << "Queue is full. Cannot enqueue more elements." << endl;
                } else {
                    cout << "Enter the value to enqueue: ";
                    cin >> value;
                    q.enqueue(value);
                }
                break;

            case 2: // Dequeue
                q.dequeue();
                break;

            case 3: // Display Queue
                q.display();
                break;

            case 4: // Exit
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

/*OUTPUT
Queue initialized. Front = -1, Rear = -1

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 1
Enter the value to enqueue: 21
Enqueued 21 to the queue.

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 1
Enter the value to enqueue: 15
Enqueued 15 to the queue.

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 1
Enter the value to enqueue: 200
Enqueued 200 to the queue.

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 3
Queue elements: 21 15 200 

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 2
Dequeued 21 from the queue.

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 3
Queue elements: 15 200 

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 1
Enter the value to enqueue: 67
Enqueued 67 to the queue.

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 1
Enter the value to enqueue: 90
Enqueued 90 to the queue.

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 1
Queue is full. Cannot enqueue more elements.

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 2
Dequeued 15 from the queue.

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 2
Dequeued 200 from the queue.

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 2
Dequeued 67 from the queue.

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 2
Dequeued 90 from the queue.

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 3
Queue is empty.

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 2
Queue Underflow! Cannot dequeue. Queue is empty.

--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display Queue
4. Exit
Enter your choice: 4
Exiting the program.
Queue destroyed.
*/
