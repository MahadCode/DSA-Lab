#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool checkSymmetric(Node *l, Node *r)
{
    if (l == nullptr && r == nullptr)
        return true;
    if (l == nullptr)
        return false;
    if (r == nullptr)
        return false;
    bool leftResult = checkSymmetric(l->left, r->right);
    bool rightResult = checkSymmetric(l->right, r->left);
    return ((l->data == r->data) && leftResult && rightResult);
}

bool isSymmetric(Node *root)
{
    if (!root)
        return true;
    return checkSymmetric(root->left, root->right);
}

void setNode(Node *rt, Node *l, Node *r)
{
    rt->left = l;
    rt->right = r;
}

int main()
{
    vector<int> x1 = {1, 2, 3, 3, 0, 0, 3};
    Node *root = new Node(x1[0]);
    Node *l11 = new Node(x1[1]);
    Node *l12 = new Node(x1[2]);
    Node *l21 = new Node(x1[3]);
    Node *l22 = new Node(x1[4]);
    Node *l23 = new Node(x1[5]);
    Node *l24 = new Node(x1[6]);
    setNode(root, l11, l12);
    setNode(l11, l21, nullptr);
    setNode(l12, nullptr, l24);

    cout << isSymmetric(root);
}