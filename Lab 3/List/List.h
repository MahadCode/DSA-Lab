#ifndef LIST_H
#define LIST_H
#include<iostream>
using namespace std;

class List {
    int* arr;
    int size;
    int capacity;
    int current;

public:
    List(int capacity);
    ~List();
    void add(int data);
    int get();
    void update(int data);
    int find(int data);
    int length();
    void start();
    void end();
    void next();
    void back();
    void copy(int* newArr, int newSize);
    void insert(int data, int position);
    void remove();
    void remove(int position);
    void clear();
    void display();
};

#endif


