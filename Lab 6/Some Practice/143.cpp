#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    void setData(int x) { data = x; }
    int getData() { return data; }
    void setNext(Node *add) { next = add; }
    Node *getNext() { return next; }
};

class List
{
    Node *head;

public:
    List() : head(nullptr) {}
    Node *gethead() { return head; }
    void insert(int x)
    {
        Node *newNode = new Node(x);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->getNext() != nullptr)
            {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
    }
};
Node *reverseList(Node *head)
{
    Node *prev = nullptr, *curr = head, *next = nullptr;
    while (curr)
    {
        next = curr->getNext();
        curr->setNext(prev);
        prev = curr;
        curr = next;
    }
    return prev;
}
void reorderList(Node *head)
{
    if (!head || !head->getNext() || !head->getNext()->getNext())
        return;
    Node *slow = head, *fast = head;
    while (fast && fast->getNext() && fast->getNext()->getNext())
    {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }
    Node *secondHalf = reverseList(slow->getNext());
    slow->setNext(nullptr); 
    Node *firstHalf = head;
    while (secondHalf)
    {
        Node *temp1 = firstHalf->getNext();
        Node *temp2 = secondHalf->getNext();

        firstHalf->setNext(secondHalf);
        secondHalf->setNext(temp1);

        firstHalf = temp1;
        secondHalf = temp2;
    }
}
void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

int main()
{
    List l;
    int size;
    cout << "Enter the size of an array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter the elements of an array:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Element number " << i + 1 << ": ";
        cin >> arr[i];
        l.insert(arr[i]);
    }

    delete[] arr; // Free dynamically allocated memory

    Node *h = l.gethead();
    cout << "Original List: ";
    printList(h);

    reorderList(h);
    cout << "Reordered List: ";
    printList(h);

    return 0;
}
