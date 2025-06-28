#include <iostream>
using namespace std;

template <typename T>
class TreeNode
{
private:
    T val;
    int height;
    TreeNode<T> *left;
    TreeNode<T> *right;

public:
    // Constructor
    TreeNode(T value)
    {
        val = value;
        height = 0;
        left = nullptr;
        right = nullptr;
    }

    // Getter for val
    T getInfo() const
    {
        return val;
    }

    // Setter for val
    void setInfo(T value)
    {
        val = value;
    }

    // Getter for height
    int getHeight() const
    {
        return height;
    }

    // Setter for height
    void setHeight(int h)
    {
        height = h;
    }

    // Getter for left
    TreeNode<T> *getLeft() const
    {
        return left;
    }

    // Setter for left
    void setLeft(TreeNode<T> *l)
    {
        left = l;
    }

    // Getter for right
    TreeNode<T> *getRight() const
    {
        return right;
    }

    // Setter for right
    void setRight(TreeNode<T> *r)
    {
        right = r;
    }
};

int height(TreeNode<int> *node)
{
    if (node != NULL)
        return node->getHeight();
    return -1;
};

TreeNode<int> *singleLeftRotation(TreeNode<int> *k1)
{
    if (k1 == NULL)
        return NULL;
    // k2 is now the new root
    TreeNode<int> *k2 = k1->getRight();
    k1->setRight(k2->getLeft()); // Y
    k2->setLeft(k1);

    // reassign heights. First k1 (demoted)
    int h = max(height(k1->getLeft()),
                height(k1->getRight()));
    k1->setHeight(h + 1);

    // k1 is now k2's left subtree
    h = max(height(k2->getRight()),
            k1->getHeight());
    k2->setHeight(h + 1);

    return k2;
}

TreeNode<int> *singleRightRotation(TreeNode<int> *k2)
{
    if (k2 == NULL)
        return NULL;
    // k1 (first node in k2's left subtree)
    // will be the new root
    TreeNode<int> *k1 = k2->getLeft();
    // Y moves from k1's right to k2's left
    k2->setLeft(k1->getRight());
    k1->setRight(k2);

    // reassign heights. First k2
    int h = max(height(k2->getLeft()),
                height(k2->getRight()));
    k2->setHeight(h + 1);
    // k2 is now k1's right subtree
    h = max(height(k1->getLeft()),
            k2->getHeight());
    k1->setHeight(h + 1);

    return k1;
}

TreeNode<int> *doubleRightLeftRotation(TreeNode<int> *k1)
{
    if (k1 == NULL)
        return NULL;
    // single right rotate with k3 (k1's right child)
    k1->setRight(singleRightRotation(k1->getRight()));
    // now single left rotate with k1 as the root
    return singleLeftRotation(k1);
}

TreeNode<int> *doubleLeftRightRotation(TreeNode<int> *k3)
{
    if (k3 == NULL)
        return NULL;
    // single left rotate with k1 (k3's left child)
    k3->setLeft(singleLeftRotation(k3->getLeft()));
    // now single right rotate with k3 as the root
    return singleRightRotation(k3);
}

TreeNode<int> *
avlInsert(TreeNode<int> *root, int info)
{
    if (root == nullptr)
        return new TreeNode<int>(info);



    if (info < root->getInfo())
    {
        root->setLeft(avlInsert(root->getLeft(), info));

        int htdiff = height(root->getLeft()) -
                     height(root->getRight());

        if (htdiff == 2)
            if (info < root->getLeft()->getInfo())
                root = singleRightRotation(root);
            else
                root = doubleLeftRightRotation(root);
    }

    else if (info > root->getInfo())
    {
        root->setRight(avlInsert(root->getRight(), info));

        int htdiff = height(root->getRight()) -
                     height(root->getLeft());

        if (htdiff == 2)
            if (info > root->getRight()->getInfo())
                root = singleLeftRotation(root);
            else
                root = doubleRightLeftRotation(root);
    }

    // else a node with info is already in the tree. In
    // case, reset the height of this root node.

    int ht = max(height(root->getLeft()),
                 height(root->getRight()));
    root->setHeight(ht + 1); // new height for root.

    return root;
}