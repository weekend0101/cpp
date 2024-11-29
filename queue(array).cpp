
#include <iostream>
using namespace std;

#define MAX 100 
class Queue {
private:
    int queue[MAX]; 
    int front, rear; 

public:
    Queue() {
        front = -1; 
        rear = -1;  
    }

 
    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow" << endl; 
            return;
        }
        if (front == -1) { 
            front = 0; 
        }
        rear++; 
        queue[rear] = value; 
        cout << value << " enqueued into the queue." << endl;
    }

        void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl; 
            return;
        }
        cout << queue[front] << " dequeued from the queue." << endl; 
        front++; 
        if (front > rear) { 
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl; 
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " "; 
        }
        cout << endl;
    }
};

int main() {
    Queue q; 
    int choice, value;

    do {
        
        cout << "Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2: 
                q.dequeue();
                break;
            case 3: 
                q.display();
                break;
            case 4: 
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
