#include<iostream>
#include<fstream>
using namespace std;


class Node
{
public:
    string object;
    Node *next;
    Node *prev;

    Node()
    {
        object = "";
        next = nullptr;
        prev = nullptr;
    }

    Node(string val)
    {
        object = val;
        next = nullptr;
        prev = nullptr;
    }
};


Node* readAndCreateList(const string &filename)
 {
 ifstream inputFile(filename);
 if (!inputFile)
 {
 cout << "Error opening input file!" << endl;
 return nullptr;
 }
 int n;
 inputFile >> n; // Read number of houses
 if (n <= 0)
 return nullptr;
 Node *head = nullptr, *tail = nullptr;
 int val;
 for (int i = 0; i < n; i++)
 {
 inputFile >> val;
 Node *newNode = new Node(val);
 if (!head)
 head = tail = newNode;
 else
 {
 }
 }
 tail->next = newNode;
 newNode->prev = tail;
 tail = newNode;
 // Make the list circular
 tail->next = head;
 head->prev = tail;
 inputFile.close();
 return head;
 }