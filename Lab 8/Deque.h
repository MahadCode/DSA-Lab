#ifndef QUEUEE_H
#define QUEUEE_H
#include <iostream>
#include <vector>
#include <algorithm> // For sorting
using namespace std;


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

#endif;