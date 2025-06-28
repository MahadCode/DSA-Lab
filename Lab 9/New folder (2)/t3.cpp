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

int findTilt(Node *root)
{
    if (root == nullptr)
        return 0;

    queue<Node *> q;
    q.push(root);

    int sum = 0;
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        int leftSum = 0;
        int rightSum = 0;

        if (current->left)
        {
            q.push(current->left);
            leftSum=(current->left)->data;
        }

        if (current->right)
        {
            q.push(current->right);
            rightSum=(current->right)->data;
        }

        int absoluteDiff = abs(leftSum - rightSum);
        sum = sum + absoluteDiff;
    }
    return sum;
};

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

