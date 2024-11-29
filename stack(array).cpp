
#include <iostream>
using namespace std;

#define MAX 100 
class Stack {
private:
    int arr[MAX]; 
    int top;      

public:
        Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow" << endl; 
            return;
        }
        arr[++top] = value; 
        cout << value << " pushed into stack" << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl; 
            return;
        }
        cout << arr[top--] << " popped from stack" << endl; 
    }

        void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl; 
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " "; 
        }
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
                break;
        }
    } while (choice != 4); 

    return 0;
}
