#include <iostream>
using namespace std;

class Node
{
public:
    string object;
    Node *nextNode;
    Node *prevNode;

    Node()
    {
        object = "";
        nextNode = nullptr;
        prevNode = nullptr;
    }

    Node(string val)
    {
        object = val;
        nextNode = nullptr;
        prevNode = nullptr;
    }
};



Node* splitNodes(Node *head)
{
    Node *prev = nullptr;
    Node* current=head;
    while (current != nullptr)
    {   
        int size = current->object.length();
        Node* next=current->nextNode;
        Node *currentInNode = nullptr;
        Node *newHead = nullptr;
        char sp1 = ' ';
        string temp = "";

        for (int i = 0; i <= size; i++)
        { 
            
            if (i==size || current->object[i] == sp1)
            {
                Node *newNode = new Node(temp);
                if(newHead==nullptr){
                   newHead=newNode;
                   currentInNode=newHead;
                   temp="";
                }
                else{
                    currentInNode->nextNode = newNode;
                    newNode->prevNode = currentInNode;
                    currentInNode = currentInNode->nextNode;
                    currentInNode->nextNode=nullptr;
                    temp = "";
                }
               
            }else{
                temp = temp + current->object[i];
            }
            
        }

        if(head==current){
            head=newHead;
            current=head;
        }
        else{
          
            (current->prevNode)->nextNode=newHead;
            newHead->prevNode=current->prevNode;
        }

        currentInNode->nextNode=next;
        if(next!=nullptr){
          next->prevNode=currentInNode;
        }
        
        current=next;
        
    }
    
    return head;
}


int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    string arr[] = {"My Name is Mahad.","I regularly go to university","Can you tell "," me some amazing test cases for this* sl >>"};
    // Insert at end
    for (int i = 0; i < 4; ++i) {
        Node* newNode = new Node();
        newNode->object = arr[i];
        if (!head) {
            head = tail = newNode;
        } else {
            tail->nextNode = newNode;
            newNode->prevNode = tail;
            tail = newNode;
        }
    }

    // Display forward
   
    Node* temp = head;
    while (temp) {
        cout << temp->object << " -> ";
        temp = temp->nextNode;
    }
    cout << "NULL\n";
    
    try{
    Node* tem = splitNodes(head);
    while (tem) {
        cout << tem->object << " -> ";
        tem = tem->nextNode;
    }
    cout << "NULL\n";
    }
    catch(exception& e){
        cout << e.what();
    }

   

}