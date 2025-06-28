#include<iostream>
using namespace std;

class Node {
    private:
    int objectX;
    int objectY;

    Node *nextNode;
    public:
    
    Node(){
        objectX=0;
        objectY=0;
        nextNode=nullptr;
    }

    int getX() { return objectX; };
    void setX(int object) { this->objectX = object; };

    int getY() { return objectY; };
    void setY(int object) { this->objectY = object; };

    Node *getNext() { return nextNode; };
    void setNext(Node *nextNode) 
     { this->nextNode = nextNode; };
};


int calculateArea(Node * head){
    Node* current=head;
    
    current=(current->getNext())->getNext();

    int width = head->getX() - current->getX();
    int height= head->getY() - current->getY();
    
    int area=width-height;

    return area;

}


int main(){
    int num;
    cin>>num;

    int num1;
    cin>>num1;

    Node* newNode=new Node;     
    newNode->setX(num);
    newNode->setY(num1);
    
    Node* head=newNode;
    Node* current=head;
 
    while(true){
     int num;
     cin>>num;
     int num1;
    cin>>num1;
     if(num!=(-1000)){
     Node* newNode=new Node;     
     newNode->setX(num);
     newNode->setY(num1);
     current->setNext(newNode);
     current=current->getNext();
     }
     else{
       current->setNext(nullptr);
       break;
     }
    }

    cout << calculateArea(head);
}