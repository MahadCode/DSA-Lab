#include "Node.cpp"
#include <iostream>

class List
{
private:
    int size;
    Node *headNode;
    Node *currentNode, *lastCurrentNode;

public:
    // Constructor
    List()
    {
        headNode = new Node();
        headNode->setNext(NULL);
        currentNode = NULL;
        size = 0;
    };


    void add(int addObject)
    {
        Node *newNode = new Node();
        newNode->set(addObject);
        if (currentNode != NULL)
        {
            newNode->setNext(currentNode->getNext());
            currentNode->setNext(newNode);
            lastCurrentNode = currentNode;
            currentNode = newNode;
        }
        else
        {
            newNode->setNext(NULL);
            headNode->setNext(newNode);
            lastCurrentNode = headNode;
            currentNode = newNode;
        }
        size++;
    };

    void remove()
    {
        if (currentNode != NULL &&
            currentNode != headNode)
        {
            lastCurrentNode->setNext(currentNode->getNext());
            delete currentNode;
            currentNode = lastCurrentNode->getNext();
            size--;
        }
    };

    void start()
    {
        lastCurrentNode = headNode;
        currentNode = headNode;
    };

    int get()
    {
        if (currentNode != NULL)
            return currentNode->get();
    };

    bool next()
    {
        if (currentNode == NULL)
            return false;
        lastCurrentNode = currentNode;
        currentNode = currentNode->getNext();
        if (currentNode == NULL || size == 0)
            return false;
        else
            return true;
    };

    void display(){
       Node* current = headNode->getNext();
       if(current->getNext()==NULL){
        return;
       }
       while(true){
          std::cout << current->get() << std::endl;
          current = current->getNext();
          if(current==NULL){
            break;
          }
       };
    };
};