
#include <iostream>
using namespace std;

struct Node {
    int data;      
    Node* next;    
};

class Stack {
private:
    Node* top;     

public:
    Stack() {
        top = nullptr;
    }

       void push(int value) {
        Node* newNode = new Node(); 
,        newNode->data = value;   ,
,        newNode->next = top;        
        top = newNode;              
        cout << value << " pushed onto stack." << endl;
    }

    void pop() {
        if (top == nullptr) { ,
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;   
        top = top->next;    ,,,,
        cout << temp->data << " popped from stack." << endl;
        delete temp;        
    }

    void display() {
        if (top == nullptr) { 
            cout << "Stack is empty." << endl;
            return;
        }
        Node* current = top;  
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current->data << " "; 
            current = current->next;      
        cout << endl;
    }
};

int main() {
    Stack stack; 
    int choice, value;

  
    do {
        cout << "Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2: 
                stack.pop();
                break;
            case 3: 
                stack.display();
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
