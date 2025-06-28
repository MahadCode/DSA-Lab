#include<iostream>
#include<vector>
using namespace std;


template <class T>
class Stack{
   vector<T> stack;
   public:
   void push(T x){
    stack.push_back(x);
   }

   void pop(){
    if(empty()){
        cout << "Stack is Empty!!" << endl;
        return;
    }
    stack.pop_back();
   }

   T top(){
    if (empty()) {
        throw std::out_of_range("Stack is Empty!!");
    }
    return stack[stack.size()-1];
   }

   bool empty(){
    return stack.size()==0;
   }

   void display(){
      if(empty()){
        cout << "Stack is Empty!!" << endl;
        return;
      }
      
      int top=stack.size()-1;
      while(top>=0){
        cout << stack[top] << "\t";
        top--;
      }
      cout << endl;
   }
};