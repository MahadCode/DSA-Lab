#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    int height;
    TreeNode<T> *left;
    TreeNode<T> *right;

    // Constructor
    TreeNode(T value)
    {
        val = value;
        height = 0;
        left = nullptr;
        right = nullptr;
    }
};

int height(TreeNode<int> *node)
{
    if (node != NULL)
        return node->height;
    return -1;
}

TreeNode<int> *singleLeftRotation(TreeNode<int> *k1)
{
    if (k1 == NULL)
        return NULL;

    TreeNode<int> *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;

    return k2;
}

TreeNode<int> *singleRightRotation(TreeNode<int> *k2)
{
    if (k2 == NULL)
        return NULL;

    TreeNode<int> *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;

    return k1;
}

TreeNode<int> *doubleRightLeftRotation(TreeNode<int> *k1)
{
    if (k1 == NULL)
        return NULL;

    k1->right = singleRightRotation(k1->right);
    return singleLeftRotation(k1);
}

TreeNode<int> *doubleLeftRightRotation(TreeNode<int> *k3)
{
    if (k3 == NULL)
        return NULL;

    k3->left = singleLeftRotation(k3->left);
    return singleRightRotation(k3);
}

TreeNode<int> *avlInsert(TreeNode<int> *root, int info)
{
    if (root == nullptr)
        return new TreeNode<int>(info);
    
    if (info == root->val)
        return root;
    else if (info < root->val)
    {
        root->left = avlInsert(root->left, info);

        int htdiff = height(root->left) - height(root->right);

        if (htdiff == 2)
        {
            if (info < root->left->val)
                root = singleRightRotation(root);
            else
                root = doubleLeftRightRotation(root);
        }
    }
    else
    {
        root->right = avlInsert(root->right, info);

        int htdiff = height(root->right) - height(root->left);

        if (htdiff == 2)
        {
            if (info > root->right->val)
                root = singleLeftRotation(root);
            else
                root = doubleRightLeftRotation(root);
        }
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    return root;
}
