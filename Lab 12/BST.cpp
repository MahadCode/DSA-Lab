#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *findMin(TreeNode *root)
{
    if (!root->left)
        return root;
    return findMin(root->left);
}

bool insert(TreeNode* root, int value)
{
    if (!root)
    {
        root = new TreeNode(value);
        return 1;
    }

    TreeNode *p = root;
    TreeNode *q = nullptr;
    while (p != nullptr && p->val != value)
    {
        q = p;
        if (value < p->val)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    if (value < q->val)
    {
        q->left = new TreeNode(value);
    }
    else if (value > q->val)
    {
        q->right = new TreeNode(value);
    }
    else
    {
        cout << "Can't Add a Duplicate " << value << " in BST !!" << endl;
        return false;
    }
    return true;
}

TreeNode *deleteNode(TreeNode *root, int info)
{
    if (!root)
        return nullptr;

    int currentValue = root->val;

    if (info < currentValue)
    {
        TreeNode *leftSubTree = deleteNode(root->left, info);
        root->left = leftSubTree;
    }
    else if (info > currentValue)
    {
        TreeNode *right = deleteNode(root->right, info);
        root->right = right;
    }
    else if (root->left && root->right)
    {
        TreeNode *inorderSucessor = findMin(root->right);
        root->val = inorderSucessor->val;
        TreeNode *rightSubTree = deleteNode(root->right, inorderSucessor->val);
        root->right = rightSubTree;
    }
    else
    {
        TreeNode *nodeToDelete = root;
        root = (root->left == nullptr) ? root->right : root->left;
        delete nodeToDelete;
    }
    return root;
};

bool search(TreeNode *root, int target)
{
    if (!root)
    {
        return 0;
    }
    if (root->val == target)
    {
        return 1;
    }
    if (root->val > target)
    {
        return search(root->left, target);
    }
    else
    {
        return search(root->right, target);
    }
}

void inorder(TreeNode *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(TreeNode *root)
{
    if (!root)
        return;
    
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}