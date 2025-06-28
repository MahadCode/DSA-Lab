#include <iostream>
using namespace std;

class Node {
public:
    int object;
    Node* nextNode;
    Node* prevNode;

    Node(int val) {
        object = val;
        nextNode = nullptr;
        prevNode = nullptr;
    }
};

class DList {
    Node* head;
    Node* tail;
    int size;

public:
    DList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->nextNode = newNode;
            newNode->prevNode = tail;
            tail = newNode;
        }
        ++size;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->nextNode = head;
            head->prevNode = newNode;
            head = newNode;
        }
        ++size;
    }

    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->object << " -> ";
            temp = temp->nextNode;
        }
        cout << "NULL\n";
    }

    void displayBackward() {
        if (!tail) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = tail;
        while (temp) {
            cout << temp->object << " -> ";
            temp = temp->prevNode;
        }
        cout << "NULL\n";
    }

    void deleteFront() {
        if (!head) {
            cout << "List is EmpTY\n";
            return;
        }
        Node* temp = head;
        head = head->nextNode;
        if (head != nullptr) head->prevNode = nullptr;
        else tail = nullptr;

        delete temp;
        --size;
    }

    void deleteEnd() {
        if (tail == nullptr) { 
            cout << "List is empty\n";
            return;
        }

        Node* temp = tail;
        tail = tail->prevNode;
        if (tail != nullptr) { 
            tail->nextNode = nullptr; 
        }
        else {
            head = nullptr;
        }
        --size;
        delete temp;

    }

    ~DList() {  // Destructor to free memory
        while (head) {
            Node* temp = head;
            head = head->nextNode;
            delete temp;
        }
    }
    

};

int main() {
    DList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtHead(5);
    
    cout << "Doubly Linked List Forward: ";
    dll.displayForward();

    cout << "Doubly Linked List Backward: ";
    dll.displayBackward();

    dll.deleteFront();
    cout << "After deleting front: ";
    dll.displayForward();

    dll.deleteEnd();
    cout << "After deleting end: ";
    dll.displayForward();

    return 0;

    
}