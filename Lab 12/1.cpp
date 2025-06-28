// L L case: Right Rotation (top)
// R R case: Left  Rotation (top)
// L R case:  Left Rotation (middle)  Right Rotation (top)
// R L case: Right Rotation (middle)   Left Rotation (top)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class TreeNode
{
public:
    int val, height;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        height = 1;
        left = right = NULL;
    }
};

void levelOrder(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        cout << temp->val << " ";

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}
bool areIdentical(TreeNode *a, TreeNode *b)
{
    if (!a && !b)
        return true;
    if (a && b)
        return (a->val == b->val) &&
               areIdentical(a->left, b->left) &&
               areIdentical(a->right, b->right);
    return false;
}
int countLevelNodes(TreeNode *root, int level)
{
    if (!root)
        return 0;
    if (level == 1)
        return 1;
    return countLevelNodes(root->left, level - 1) +
           countLevelNodes(root->right, level - 1);
}

int sumNodes(TreeNode *root)
{
    if (!root)
        return 0;
    return root->val + sumNodes(root->left) + sumNodes(root->right);
}

void printLeaves(TreeNode *root)
{
    if (!root)
        return;

    if (!root->left && !root->right)
        cout << root->val << " ";

    printLeaves(root->left);
    printLeaves(root->right);
}

TreeNode *LCA(TreeNode *root, int n1, int n2)
{
    if (!root)
        return nullptr;

    if (n1 < root->val && n2 < root->val)
        return LCA(root->left, n1, n2);
    else if (n1 > root->val && n2 > root->val)
        return LCA(root->right, n1, n2);
    else
        return root;
}

int countNodes(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int kthSmallest(TreeNode *root, int &k)
{
    if (!root)
        return -1;

    int left = kthSmallest(root->left, k);
    if (left != -1)
        return left;

    k--;
    if (k == 0)
        return root->val;

    return kthSmallest(root->right, k);
}

// Example usage:
int findKthSmallest(TreeNode *root, int k)
{
    return kthSmallest(root, k);
}

bool search(TreeNode *root, int key)
{
    if (!root)
        return false;
    if (key == root->val)
        return true;
    if (key < root->val)
        return search(root->left, key);
    return search(root->right, key);
}

TreeNode *minValueNode(TreeNode *node)
{
    TreeNode *current = node;
    while (current->left)
        current = current->left;
    return current;
}
int getheight(TreeNode *root)
{
    if (!root)
        return 0;
    return root->height;
}
int getbalance(TreeNode *root)
{
    return getheight(root->left) - getheight(root->right);
}


TreeNode *rightrotation(TreeNode *root)
{
    TreeNode *child = root->left;
    TreeNode *childright = child->right;
    child->right = root;
    root->left = child->right;
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    return child;
}
TreeNode *leftrotation(TreeNode *root)
{
    TreeNode *child = root->right;
    TreeNode *childleft = child->left;
    child->left = root;
    root->right = child->left;
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    return child;
}
TreeNode *insert(TreeNode *root, int key)
{
    if (!root)
        return new TreeNode(key);
    if (key < root->val)
    {
        root->left = insert(root->left, key);
    }
    if (key > root->val)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(getheight(root->left), getheight(root->right));

    int balance = getbalance(root);
    // left left case
    if (balance > 1 && key < root->left->val)
    {
        return rightrotation(root);
    }
    // right right case
    else if (balance < -1 && root->right->val < key)
    {
        return leftrotation(root);
    }
    // left right case
    else if (balance > 1 && key > root->left->val)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    // right left case
    else if (balance < -1 && root->right->val > key)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }
    // not UN-BALANCE case
    else
    {
        return root;
    }


}
void displayDetails(TreeNode *root)
{
    if (!root)
        return;
    displayDetails(root->left);
    cout << "Key: " << root->val << ", Height: " << root->height
         << ", Balance: " << getbalance(root) << endl;
    displayDetails(root->right);
}

void toArray(TreeNode *root, vector<int> &arr)
{
    if (!root)
        return;
    toArray(root->left, arr);
    arr.push_back(root->val);
    toArray(root->right, arr);
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left || !root->right)
        {
            TreeNode *temp = root->left ? root->left : root->right;
            if (!temp)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            TreeNode *temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    int balance = getbalance(root);

    if (balance > 1 && getbalance(root->left) >= 0)
        return rightrotation(root);
    
    if (balance > 1 && getbalance(root->left) < 0)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    if (balance < -1 && getbalance(root->right) <= 0)
        return leftrotation(root);
    if (balance < -1 && getbalance(root->right) > 0)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

    return root;
}