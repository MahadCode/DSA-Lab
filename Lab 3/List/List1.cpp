#include<iostream>
using namespace std;

class List {
    int* arr;
    int size;
    int capacity;
    int current;

public:
    List(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = 0;
        }
        size = 0;
        current = -1;
    }

    ~List() {
        delete[] arr;
    }

    void add(int data) {
        if (size == capacity) {
            arr[size - 1] = data;
        }
        else {
            arr[size] = data;
            size++;
        }
        current = size - 1;
    }

    int get() {
        if (size == 0 || current < 0) {
            cout << "List is empty or current position is invalid." << endl;
            return -1;
        }
        return arr[current];
    }

    void update(int data) {
        if (size == 0 || current < 0) {
            cout << "List is empty or invalid position." << endl;
            return;
        }
        arr[current] = data;
    }

    int find(int data) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == data) {
                return i;
            }
        }
        return -1;
    }

    int length() {
        return size;
    }

    void start() {
        current = 0;
    }

    void end() {
        if (size > 0)
            current = size - 1;
    }

    void next() {
        if (current < size - 1) {
            current++;
        }
    }

    void back() {
        if (current > 0) {
            current--;
        }
    }

    void copy(int* newArr, int newSize) {
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

    void insert(int data, int position) {
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

    void remove() {
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

    void remove(int position) {
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

    void clear() {
        size = 0;
        current = -1;
    }

    void display() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void dis() {
        cout << current << endl;
        cout << size << endl;
    }
};


int main() {
    List list(50);

    // Test the List ADT
    list.add(2);
    list.dis();
    list.add(6);
    list.add(8);
    list.add(7);
    list.add(1);
    list.dis();

    std::cout << "Initial List: ";
    list.display();

    list.insert(9,3); // Insert 9 at position 3
    std::cout << "After adding 9 at position 3: ";
    list.display();

    list.dis();

    list.remove(); // Remove element at current position
    std::cout << "After removing current element at last position : ";
    list.display();

    list.update(5); 
    std::cout << "After updating current element: ";
    list.display();

    std::cout << "Element at current position: " << list.get() << std::endl;

    std::cout << "Position of element 8: " << list.find(8) << std::endl;

    std::cout << "Length of the list: " << list.length() << std::endl;

    list.start();
    std::cout << "Current element after start(): " << list.get() << std::endl;

    list.end();
    std::cout << "Current element after end(): " << list.get() << std::endl;

    list.clear();
    std::cout << "List after clear(): ";
    list.display();

    return 0;
}