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
    if(isEmpty()){
        cout << "Stack is Empty!!" << endl;
        return;
    }
    stack.pop_back();
   }

   T top(){
    if (isEmpty()) {
        throw std::out_of_range("Stack is Empty!!");
    }
    return stack[stack.size()-1];
   }

   bool isEmpty(){
    return stack.size()==0;
   }

   void display(){
      if(isEmpty()){
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



int main(){
//    Stack<int> s1;
//    cout << s1.isEmpty() << endl;

//    s1.push(1);
//    s1.push(2);
//    s1.push(3);
//    s1.push(4);
//    s1.display();
   
//    cout << "Top:\t"<< s1.top() << endl;
//    s1.pop();
//    cout << "Top:\t"<< s1.top() << endl;
//    s1.display();

Stack<string> s;
s.push("Mahad is my name");
s.push("I am a boy");
s.push("I love coding");
s.display(); // Output: 30  20  10

cout << "Top element:\n" << s.top() << endl; // Output: 30
s.pop();
s.display(); // Output: 20  10
}