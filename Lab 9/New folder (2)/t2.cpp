#include <iostream>
#include<queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void levelOrder1(Node* root,vector<int>& ans) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        ans.push_back(current->data); 

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
};

void levelOrder2(Node* root,vector<int>& ans) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        ans.push_back(current->data); 

        if (current->right)
            q.push(current->right);
        if (current->left)
            q.push(current->left);
    }
};



bool isSymmetric(Node* root){
    if(root==nullptr){
        return true;
    } 
    Node* leftR=root->left;
    Node* rightR=root->right;

    if(leftR == nullptr && rightR==nullptr){
        return true;
    }

    
    if(leftR == nullptr || rightR==nullptr){
        return false;
    }

    vector<int> ans1;
    vector<int> ans2;
    levelOrder1(leftR,ans1);
    levelOrder2(rightR,ans2);
    return ans1==ans2;
}



void setNode(Node* rt,Node* l,Node* r){
    rt->left=l;
    rt->right=r;
}



int main(){
    vector<int> x1={1,2,3,3,0,0,3};
    Node* root=new Node(x1[0]);
    Node* l11=new Node(x1[1]);
    Node* l12=new Node(x1[2]);
    Node* l21=new Node(x1[3]);
    Node* l22=new Node(x1[4]);
    Node* l23=new Node(x1[5]);
    Node* l24=new Node(x1[6]);
    setNode(root,l11,l12);
    setNode(l11,l21,nullptr);
    setNode(l12,nullptr,l24);


    cout << isSymmetric(root);

}