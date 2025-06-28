#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <iostream>
using namespace std;

class List
{
public:
    List()
    {
        headNode = new Node();
        headNode->setNext(nullptr);
        currentNode = nullptr;
        lastCurrentNode = nullptr;
        size = 0;
    }
    void reverse() {
        Node* prev = nullptr;
        Node* current = headNode;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->getNext();  
            current->setNext(prev);    
            prev = current;             
            current = next;             
        }
        headNode = prev;  
    }
    void add(int addObject)
    {
        Node *newNode = new Node();
        newNode->set(addObject);

        if (currentNode != nullptr)
        {
            newNode->setNext(currentNode->getNext());
            currentNode->setNext(newNode);
            lastCurrentNode = currentNode;
            currentNode = newNode;
        }
        else
        {
            newNode->setNext(nullptr);
            headNode->setNext(newNode);
            lastCurrentNode = headNode;
            currentNode = newNode;
        }

        size++;
    }
    int get()
    {
        if (currentNode != nullptr)
            return currentNode->get();
    }
    bool next()
    {
        if (currentNode == nullptr)
            return false;
        lastCurrentNode = currentNode;
        currentNode = currentNode->getNext();
        if (currentNode == nullptr || size == 0)
            return false;
        else
            return true;
    };
    void start()
    {
        lastCurrentNode = headNode;
        currentNode = headNode;
    }
    void remove()
    {
        if (currentNode != nullptr &&
            currentNode != headNode)
        {
            lastCurrentNode->setNext(currentNode->getNext());
            delete currentNode;
            currentNode = lastCurrentNode->getNext();
            size--;
        }
    };
    int length()
    {
        return size;
    };
    void insertEnd(int value)
    {
        Node *newNode = new Node();
        newNode->set(value);
        if (headNode == nullptr)
        {
            headNode = newNode;
        }
        else
        {
            Node *temp = headNode;
            while (temp->getNext() != nullptr)
            {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
            size++;
        }
    }
    void insertFront(int value)
    {
        Node *newnode = new Node();
        if (headNode == nullptr)
        {
            newnode->set(value);
            headNode = newnode;
            size++;
        }
        else
        {
            Node *newnode = new Node();
            newnode->setNext(headNode->getNext());
            newnode->set(value);
            headNode = newnode;
            size++;
        }
    }
    int countNodes()
    {
        Node *temp = headNode;
        int count = 0;
        if (headNode == nullptr)
        {
            return 0;
        }
        else
        {
            while (temp)
            {
                temp = temp->getNext();
                count++;
            }
            return count - 1;
        }
    }
    bool search(int value)
    {
        Node *temp = headNode;
        if (headNode == nullptr)
        {
            return false;
        }
        else
        {
            while (temp)
            {
                if (temp->get() == value)
                {
                    return true;
                }
            }
            return false;
        }
    }
    void display()
    {
        Node *temp = headNode->getNext();
        while (temp != nullptr)
        {
            std::cout << temp->get() << " -> ";
            temp = temp->getNext();
        }
        std::cout << "NULL\n";
    }
    void displayReverse()
    {
        Node *temp = headNode->getNext();
        Node *prev = nullptr;
        Node *next = nullptr;
        while (temp != nullptr)
        {
            next = temp->getNext();
            temp->setNext(prev);
            prev = temp;
            temp = next;
        }
        headNode->setNext(prev);
        temp = headNode->getNext();
        while (temp != nullptr)
        {
            std::cout << temp->get() << " -> ";
            temp = temp->getNext();
        }
        std::cout << "NULL\n";
    }

    ~List()
    {
        Node *temp = headNode;
        while (temp != nullptr)
        {
            Node *next = temp->getNext();
            delete temp;
            temp = next;
        }
    }

private:
    Node *headNode;
    Node *currentNode;
    Node *lastCurrentNode;
    int size;
};

#endif