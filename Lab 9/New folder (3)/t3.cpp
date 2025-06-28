#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// A binary tree node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int subtreeSum(Node* node, int& totalTilt) {
    if (!node) return 0;
    
    int leftSum = subtreeSum(node->left, totalTilt);
    int rightSum = subtreeSum(node->right, totalTilt);
    
    totalTilt += abs(leftSum - rightSum);
    
    return node->data + leftSum + rightSum;
}

int findTilt(Node* root) {
    int totalTilt = 0;
    subtreeSum(root, totalTilt);
    return totalTilt;
}

void setNode(Node* rt,Node* l,Node* r){
    rt->left=l;
    rt->right=r;
}

int main()
{
    vector<int> x1 = {1};
    Node *root = new Node(x1[0]);
    // Node *l11 = new Node(x1[1]);
    // Node *l12 = new Node(x1[2]);
    // setNode(root,l11,l12);

    cout << findTilt(root);
}

