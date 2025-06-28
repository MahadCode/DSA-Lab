#include<iostream>
using namespace std;

class Node {
    private:
    int object;
    Node *nextNode;
    public:
    Node(){
        object=0;
        nextNode = nullptr;
    }
    int get() { return object; };
    void set(int object) { this->object = object; };
    Node *getNext() { return nextNode; };
    void setNext(Node *nextNode) 
     { this->nextNode = nextNode; };
};



Node*  compressList(Node* head){
    Node* current=head;

    while(current!=nullptr){
        Node* last = current;
        Node* checkDup = current->getNext();
        int count=0;
        if(checkDup!=nullptr){
        while(checkDup->get()==current->get()){
            last=checkDup;  
            checkDup = checkDup->getNext();
            count++;
            if(checkDup==nullptr){
                break;
            }
        }
        }
        if(count==0){
            current = current->getNext();
        }
        else{
            count++;
            Node* newNode= new Node;
            newNode->set(count);
            current->setNext(newNode);
            newNode->setNext(last->getNext());

            current = newNode->getNext();
        } 
    }

    return head;
}

void display(Node* head){
    Node* current=head;
    if(current==nullptr){
     return;
    }
    while(true){
       std::cout << current->get() << std::endl;
       current = current->getNext();
       if(current==nullptr){
         break;
       }
    };
    return;
 };


int main(){
   

   int num;
   cin>>num;
   Node* newNode=new Node;     
   newNode->set(num);
   
   Node* head=newNode;
   Node* current=head;

   while(true){
    int num;
    cin>>num;
    if(num!=(-1000)){
    Node* newNode=new Node;     
    newNode->set(num);
    current->setNext(newNode);
    current=current->getNext();
    }
    else{
      current->setNext(nullptr);
      break;
    }
   }

   display(head);

   Node* n=compressList(head);

   display(n);
}