#include <iostream>
#include<string>
#include <stdexcept>
using namespace std;

template <class T>
class Stack {
    T* arr;
    int Top;
    int capacity;
    void resize() {
        capacity *= 2; // Double the size
        T* newArr = new T[capacity];
        for (int i = 0; i <= Top; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    Stack() {
        capacity = 10000; // Initial size of stack
        arr = new T[capacity];
        Top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T x) {
        if (Top + 1 == capacity) {
            resize();
        }
        arr[++Top] = x;
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        Top--;
    }

    T top() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is Empty!!");
        }
        return arr[Top];
    }

    bool isEmpty() {
        return Top == -1;
    }

    void display() {
        for (int i = Top; i >= 0; i--) {
            cout << arr[i];
        }
        cout << endl;
    }
};

// Example Usage
int main() {
    Stack<string> s;
    s.push("Mahad is my name");
    s.push("I am a boy");
    s.push("I love coding");
    s.display(); // Output: 30  20  10

    cout << "Top element:\n" << s.top() << endl; // Output: 30
    s.pop();
    s.display(); // Output: 20  10

    return 0;
}
