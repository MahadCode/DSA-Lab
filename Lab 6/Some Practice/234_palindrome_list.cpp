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
    void setData(int x)
    {
        data = x;
    }
    int getData()
    {
        return data;
    }
    void setNext(Node *add)
    {
        next = add;
    }
    Node *getNext()
    {
        return next;
    }
};
class List
{
    Node *head;

public:
    List() : head(nullptr) {}
    Node *gethead()
    {
        return head;
    }
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
bool isPalindrome(Node *head)
{
    stack<int> st;
    int size = 0;
    Node *temp = head;
    while (temp)
    {
        size++;
        temp = temp->getNext();
    }
    Node *temp1 = head;
    for (int i = 0; i < size / 2; i++)
    {
        st.push(temp1->getData());
        temp1=temp1->getNext();
    }
    if (size % 2 != 0)
    {
        temp1 = temp1->getNext();
    }
    while (temp1)
    {
        if (temp1->getData() != st.top())
        {
            return false;
        }
        st.pop();
        temp1 = temp1->getNext();
    }
    return true;
}
int main()
{
    List l;
    int size;
    cout<<"Enter the size of an array: ";
    cin>>size;
    int* arr=new int[size];
    cout<<"Enter the elements of an array\n ";
    for(int i=0;i<size;i++)
    {
        cout<<"Element number "<<i+1<<": ";
        cin>>arr[i];
        l.insert(arr[i]);
    }
    Node* h=l.gethead();
    bool a;
    a=isPalindrome(h);
    cout<<a;

}