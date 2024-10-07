# **Queue in C++**
# Experiment 19  To study and implement Queue implementation using array. Menu options - i) Insert ii) Delete iii) Display iv) exit


A **queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle, meaning the first element added is the first one to be removed. Below is a simple C program to implement a queue using an array, along with options for `Enqueue`, `Dequeue`, `Display`, and `Exit` using a `switch` statement.
### **Advantages of Queue**

1. **FIFO Principle**:
   - The **First In, First Out** nature of queues is ideal for managing tasks in the order they arrive (e.g., in operating systems and task scheduling).

2. **Efficient Task Scheduling**:
   - Queues are widely used in **task scheduling** systems like CPU scheduling and print spooling where tasks are completed in the order they were added.

3. **Handling Asynchronous Data**:
   - Queues are useful in **asynchronous** data transfer, such as buffering, where the order of data matters (e.g., I/O buffers, network data packets).

4. **Breadth-First Search (BFS)**:
   - Queues are crucial in **BFS** algorithms used in graph and tree traversal, where nodes are processed in the order they are discovered.

5. **Real-World Applications**:
   - Queues model many real-world scenarios like lines at a ticket counter or customer service, where the first person in line is the first to be served.

### **Disadvantages of Queue**

1. **Fixed Size (in Array-based Queues)**:
   - If implemented using arrays, the queue size is **fixed**, leading to **queue overflow** when it is full.

2. **No Random Access**:
   - Similar to stacks, queues do not support random access to elements. You can only access the element at the **front**, making it inefficient for some tasks.

3. **Wasted Memory (in Array-based Queues)**:
   - When elements are dequeued from the front in an array-based queue, the space cannot be reused, leading to **memory wastage** unless you reset or use a circular queue.

4. **Queue Overflow and Underflow**:
   - **Overflow** occurs when attempting to add an element to a full queue.
   - **Underflow** occurs when trying to remove an element from an empty queue.

5. **Circular Queue Implementation Needed**:
   - In some cases, to avoid memory wastage in array-based queues, you need to implement a **circular queue**, which can be more complex than a simple queue.
  
  

## Code
~~~
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
~~~

## Code output 
![](https://github.com/Sundar13905/queue/blob/main/Exp_19_out.png)

## Conclusion
We leant how to implement queue in C++
