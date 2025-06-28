#include <iostream>
using namespace std;

class Node
{
private:
    int object;
    Node* nextNode;

public:
    Node()
    {
        object = 0;
        nextNode = nullptr;
    }
    int get() { return object; };
    void set(int object) { this->object = object; };
    Node* getNext() { return nextNode; };
    void setNext(Node* nextNode)
    {
        this->nextNode = nextNode;
    };
};

// Node *removeZeroSumSublist(Node *head)
// {
//     Node *start = head;

//     while (start != nullptr)
//     {
//         Node *current = start;
//         int sum = current->get();
//         bool found=false;
//         while (current != nullptr)
//         {
//             Node *next = current->getNext();
//             sum += next->get();
//             if (sum == 0)
//             {
//                 if (start == head)
//                 {
//                     head = next->getNext();
//                     start=head;
//                     current = start;
//                     found=true;
//                 }
//                 else
//                 {
//                     start->setNext(next->getNext());
//                     found=true;
//                 }
//                 break;
//             }
//             else
//             {
//                 current = current->getNext();
//             }
//         }
//         if(!found){
//             start=start->getNext();       
//          }
//     }

//     return head;
// }

// Node *removeZeroSumSublist(Node *head)
// {
//     Node *start = head;

//     while (start != nullptr)
//     {
//         Node *current = start;
//         int sum = current->get();
//         while (current != nullptr)
//         {
//             Node *next = current->getNext();
//             sum += next->get();
//             if (sum == 0)
//             {
//                     head = next->getNext();
//                     start=head;
//                     break;
//             }
//             else
//             {   
//                 current = current->getNext();
//             }

//         }
//         if(head->getNext()==nullptr){
//             break;
//         }
//         if(start!=head){
//             start=start->getNext();
//         }

//     }

//     return head;
// }


Node* removeZeroSumSublist(Node* head) {
    int size = 0;
    Node* current = head;
    while (current != nullptr) {
        current = current->getNext();
        size++;
    }

    Node* start = head;
    Node* prev = nullptr;
    for (int i = 0; i < size; i++) {
        Node* end = start;
        int sum = 0;
        for (int j = i; j < size; j++) {
          
            sum += end->get();
        
            if (sum == 0) {
                if (start == head) {
                    head = end->getNext();
                    start = head;
                    prev = nullptr;
                    sum = 0;
                }
                else {
                    prev->setNext(end->getNext());
                    if (end->getNext() == nullptr) {
                        break;
                    }
                    start = end->getNext();
                    end = start;
                }
            }

            if (end->getNext() == nullptr) {
                break;
            }

            end = end->getNext();
        }
        
        if (start == nullptr) {
            break;
        }

        if (start->getNext() == nullptr) {
            break;
        }
        prev = start;
        start = start->getNext();
    }

    return head;
}

void display(Node* head)
{   
    cout << "List:\n";
    Node* current = head;
    if (current == nullptr)
    {
        return;
    }
    while (true)
    {
        std::cout << current->get() << "\t";
        current = current->getNext();
        if (current == nullptr)
        {
            break;
        }
    };
    cout << endl;
    return;
};

int main()
{

    int num;
    cin >> num;
    Node* newNode = new Node;
    newNode->set(num);

    Node* head = newNode;
    Node* current = head;

    while (true)
    {
        int num;
        cin >> num;
        if (num != (-1000))
        {
            Node* newNode = new Node;
            newNode->set(num);
            current->setNext(newNode);
            current = current->getNext();
        }
        else
        {
            current->setNext(nullptr);
            break;
        }
    }

    display(head);

    Node* n = removeZeroSumSublist(head);

    display(n);
}