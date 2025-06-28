#include"List.h"

int main() {
    List list(INT_MAX);

    // Test the List ADT
    list.add(2);
    list.add(6);
    list.add(8);
    list.add(7);
    list.add(1);

    std::cout << "Initial List: ";
    list.display();

    list.insert(9, 3); // Insert 9 at position 3
    std::cout << "After adding 9 at position 3: ";
    list.display();

    list.remove(); // Remove element at current position
    std::cout << "After removing current element at last : ";
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