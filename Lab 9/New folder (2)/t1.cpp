#include <iostream>
#include<queue>
#include<stack>
#include <algorithm>
#include<string>
using namespace std;

// A binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* str2tree(string s){
    int size=s.length();
    if(size==0){
        return nullptr;
    }
    
    string f="";
    for(int i=0; i<size; i++){
        char ch=s[i];
        if(ch=='('){
            break;
        }
        f=f+ch;
    }
    int num = stoi(f);
    Node* root=new Node(num);
    if(size==1){
        return root;
    }

    int position=1;
    string leftS="";

    stack<char> st;
    while(position<size){
      char ch=s[position];
      if(ch=='('){
        st.push(ch);
      }
      else if(ch==')'){
        st.pop();
      }

      
      if(st.empty()){
        break;
      }
      if(position!=1){
        leftS = leftS + ch;
      }
      position++;
    }
    
    position++;

    Node* rootL=str2tree(leftS);



    string rightS="";
    bool first=true;
    stack<char> st1;
    while(position<size){
      char ch=s[position];
      if(ch=='('){
        st1.push(ch);
      }
      else if(ch==')'){
        st1.pop();
      }

      
      if(st1.empty()){
        break;
      }
      if(!first){
        rightS = rightS + ch;
      }
      first=false;
      position++;
    }
     
    position++;
    Node* rootR=str2tree(rightS);

    root->left=rootL;
    root->right=rootR;

    return root;
}

void preorderTraversal(Node* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

int main(){
  string a= "1(2)(3(6))";
  Node* root=str2tree(a);
  preorderTraversal(root);
}