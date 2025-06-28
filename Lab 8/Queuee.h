#ifndef QUEUEE_H
#define QUEUEE_H
#include <iostream>
#include <vector>
#include <algorithm> // For sorting
using namespace std;

template <typename T>
class Queuee {
private:
    T* arr;
    int front, rear, capacity, count;

public:
    // Constructor
    Queuee(int size = 10) {
        arr = new T[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor
    ~Queuee() {
        delete[] arr;
    }

    // Enqueue operation
    void enqueue(T item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << item << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue" << endl;
            return;
        }
        front = (front + 1) % capacity;
        count--;
    }

    // Get front element
    T getFront() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty.");
        }
        return arr[front];
    }

    // Get rear element
    T getRear() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty.");
        }
        return arr[rear];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (count == 0);
    }

    // Check if the queue is full
    bool isFull() {
        return (count == capacity);
    }

    // Get size of the queue
    int size() {
        return count;
    }
};

template <typename T>
class Deque {
private:
    T* arr;
    int front, rear, size, capacity;

public:
    Deque(int cap=10) {
        capacity = cap;
        arr = new T[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~Deque() { delete[] arr; }

    bool isFull() { return size == capacity; }

    bool isEmpty() { return size == 0; }

    void insertFront(T item) {
        if (isFull()) {
            cout << "Deque is full!\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = item;
        size++;
    }

    void insertRear(T item) {
        if (isFull()) {
            cout << "Deque is full!\n";
            return;
        }
        if (rear == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = item;
        size++;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }
        rear = (rear - 1 + capacity) % capacity;
        size--;
    }

    T getFront() {
        if (isEmpty()) throw runtime_error("Deque is empty.");
        return arr[front];
    }

    T getRear() {
        if (isEmpty()) throw runtime_error("Deque is empty.");
        return arr[rear];
    }
};

template <typename T>
class PriorityQueue {
private:
    vector<T> pq;  // Using vector as a dynamic array

public:
    void enqueue(T item) {
        pq.push_back(item);
        sort(pq.begin(), pq.end()); // Sort to maintain priority order
    }

    void dequeue() {
        if (pq.empty()) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        pq.erase(pq.begin()); // Remove element with highest priority (smallest)
    }

    T getFront() {
        if (pq.empty()) throw runtime_error("Priority Queue is empty.");
        return pq.front();
    }

    bool isEmpty() { return pq.empty(); }

    int size() { return pq.size(); }
};

class Stack {
    private:
        Queuee<int> q1, q2;
    
    public:
        void push(int x) {
            q2.enqueue(x);
            while (!q1.isEmpty()) {
                q2.enqueue(q1.getFront());
                q1.dequeue();
            }
            swap(q1, q2);
        }
    
        void pop() {
            if (q1.isEmpty()) return;
            q1.dequeue();
        }
    
        int top() {
            return q1.isEmpty() ? -1 : q1.getFront();
        }
    };

#endif