
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* head; 
    Node* tail; 

public:
    Queue() : head(nullptr), tail(nullptr) {} 
        void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) { 
            head = tail = newNode; 
        } else {
            tail->next = newNode; 
            tail = newNode; 
        }
        cout << value << " enqueued to queue." << endl;
    }

    
    void dequeue() {
        if (head == nullptr) { 
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = head; 
        cout << head->data << " dequeued from queue." << endl;
        head = head->next; 

                if (head == nullptr) {
            tail = nullptr; 
        }
        delete temp; 
    }

    void display() {
        if (head == nullptr) { 
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = head; 
        cout << "Queue elements: ";
        while (current != nullptr) {
            cout << current->data << " "; 
            current = current->next; 
        }
        cout << endl;
    }

    ~Queue() { 
        while (head != nullptr) {
            dequeue(); 
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
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
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
