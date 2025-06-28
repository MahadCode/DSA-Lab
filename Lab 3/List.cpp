#include "List.h"

List::List(int capacity) {
    this->capacity = capacity;
    arr = new int[capacity];
    for (int i = 0; i < capacity; i++) {
        arr[i] = 0;
    }
    size = 0;
    current = -1;
}

List::~List() {
    delete[] arr;
}

void List::add(int data) {
    if (size == capacity) {
        arr[size - 1] = data;
    }
    else {
        arr[size] = data;
        size++;
    }
    current = size - 1;
}

int List::get() {
    if (size == 0 || current < 0) {
        cout << "List is empty or current position is invalid." << endl;
        return -1;
    }
    return arr[current];
}

void List::update(int data) {
    if (size == 0 || current < 0) {
        cout << "List is empty or invalid position." << endl;
        return;
    }
    arr[current] = data;
}

int List::find(int data) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == data) {
            return i;
        }
    }
    return -1;
}

int List::length() {
    return size;
}

void List::start() {
    current = 0;
}

void List::end() {
    if (size > 0)
        current = size - 1;
}

void List::next() {
    if (current < size - 1) {
        current++;
    }
}

void List::back() {
    if (current > 0) {
        current--;
    }
}

void List::copy(int* newArr, int newSize) {
    if (newSize > capacity) {
        cout << "Not enough capacity to copy elements." << endl;
        return;
    }
    for (int i = 0; i < newSize; i++) {
        arr[i] = newArr[i];
    }
    size = newSize;
    current = size - 1;
}

void List::insert(int data, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position" << endl;
        return;
    }
    if (size == capacity) {
        for (int i = size - 1; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = data;
        current = position;
    }
    else {
        for (int i = size; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = data;
        size++;
        current = position;
    }
}

void List::remove() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    }
    for (int i = current; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    if (current >= size) {
        current = size - 1;
    }
}

void List::remove(int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position" << endl;
        return;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    if (current >= size) {
        current = size - 1;
    }
}

void List::clear() {
    size = 0;
    current = -1;
}

void List::display() {
    if (size == 0) {
        cout << "List is empty" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//void List::dis() {
//    cout << "Current: " << current << endl;
//    cout << "Size: " << size << endl;
//}


