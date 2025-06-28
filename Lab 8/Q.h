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

#endif;