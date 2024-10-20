// Varun Pendem
// PRN: 23070123149
#include <iostream>
using namespace std;

#define MAX 5  // Maximum size of the queue

class Queue {
    int front, rear;
    int queue[MAX];

public:
    // Constructor to initialize front and rear to -1 (empty queue)
    Queue() {
        front = rear = -1;
    }

    // Enqueue function to add an element to the queue
    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow! Cannot add more elements." << endl;
        } else {
            if (front == -1) front = 0;  // First element being added
            queue[++rear] = value;       // Increment rear and add value
            cout << value << " enqueued into the queue." << endl;
        }
    }

    // Dequeue function to remove the front element from the queue
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! No elements to dequeue." << endl;
        } else {
            cout << queue[front++] << " dequeued from the queue." << endl;
            if (front > rear) {  // Reset the queue when empty
                front = rear = -1;
            }
        }
    }

    // Display function to print all elements in the queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements are: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    while (1) {
        // Display the menu options
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch statement to handle the operations
        switch (choice) {
            case 1:  // Enqueue operation
                cout << "Enter the value to enqueue: ";
                cin >> value;
                q.enqueue(value);   // Call enqueue function with the input value
                break;

            case 2:  // Dequeue operation
                q.dequeue();  // Call dequeue function
                break;

            case 3:  // Display operation
                q.display();  // Call display function to show elements in the queue
                break;

            case 4:  // Exit the program
                cout << "Exiting..." << endl;
                return 0;

            default:  // Handle invalid option
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }

    return 0;
}
