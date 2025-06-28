#include <iostream>
#include <stack>

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

Node *addTwoNumbers(Node *l1, Node *l2)
{
    stack<int> st1, st2;
    
    while (l1)
    {
        st1.push(l1->getData());
        l1 = l1->getNext();
    }

    while (l2)
    {
        st2.push(l2->getData());
        l2 = l2->getNext();
    }

    Node *head = nullptr;
    int carry = 0;

    while (!st1.empty() || !st2.empty() || carry)
    {
        int sum = carry;
        if (!st1.empty())
        {
            sum += st1.top();
            st1.pop();
        }
        if (!st2.empty())
        {
            sum += st2.top();
            st2.pop();
        }

        carry = sum / 10;
        Node *newNode = new Node(sum % 10);
        newNode->setNext(head);
        head = newNode;
    }

    return head;
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
    List l1, l2;
    int size1, size2;

    cout << "Enter the size of your first linked list: ";
    cin >> size1;
    cout << "Enter the elements:\n";
    for (int i = 0; i < size1; i++)
    {
        int val;
        cout << "Element " << i + 1 << " : ";
        cin >> val;
        l1.insert(val);
    }

    cout << "Enter the size of your second linked list: ";
    cin >> size2;
    cout << "Enter the elements:\n";
    for (int i = 0; i < size2; i++)
    {
        int val;
        cout << "Element " << i + 1 << " : ";
        cin >> val;
        l2.insert(val);
    }

    Node *result = addTwoNumbers(l1.gethead(), l2.gethead());
    cout << "Sum List: ";
    printList(result);

    return 0;
}
