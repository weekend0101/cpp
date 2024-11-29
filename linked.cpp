#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    Node* createNode(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

    void displayList() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

        void insertAtFront(int value) {
        Node* newNode = createNode(value);
        newNode->next = head;
        head = newNode;
    }

    
    void insertAtRear(int value) {
        Node* newNode = createNode(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAfterPosition(int value, int position) {
        Node* newNode = createNode(value);
        Node* current = head;
        for (int i = 0; i < position && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Position does not exist." << endl;
            delete newNode;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteFirstNode() {
        if (head == nullptr) {
            cout << "The list is empty. Nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted the first node." << endl;
    }

    void deleteLastNode() {
        if (head == nullptr) {
            cout << "The list is empty. Nothing to delete." << endl;
            return;
        }
        if (head->next == nullptr) { 
            delete head;
            head = nullptr;
            cout << "Deleted the last node." << endl;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next; 
        current->next = nullptr; 
        cout << "Deleted the last node." << endl;
    }

        void deleteAfterPosition(int position) {
        Node* current = head;
        for (int i = 0; i < position && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) {
            cout << "No node exists after position " << position << "." << endl;
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Deleted node after position " << position << "." << endl;
    }

    ~SinglyLinkedList() {
        while (head != nullptr) {
            deleteFirstNode();
        }
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtRear(10);
    list.insertAtRear(20);
    list.insertAtRear(30);
    cout << "Initial list: ";
    list.displayList();

    list.insertAtFront(5);
    cout << "After inserting 5 at front: ";
    list.displayList();

    list.insertAfterPosition(25, 1); 
    cout << "After inserting 25 after position 1: ";
    list.displayList();

    list.deleteFirstNode();
    cout << "After deleting the first node: ";
    list.displayList();

    list.deleteLastNode();
    cout << "After deleting the last node: ";
    list.displayList();

    list.deleteAfterPosition(1); 
    cout << "After deleting node after position 1: ";
    list.displayList();

    return 0;
}
