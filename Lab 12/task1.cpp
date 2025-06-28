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


bool isomorphic(TreeNode* root1,TreeNode* root2){
    if(!root1 && !root2) true;

    if(!root1 || !root2) return false;

    if(root1->val != root2->val) return false;

    return isomorphic(root1->left,root2->left) || isomorphic(root1->right,root2->right) || isomorphic(root1->left,root2->right) ||isomorphic(root1->right,root2->left) ;

}


bool isBalanced(TreeNode *root, int &height)
{
    if (!root)
    {
        height = 0;
        return true;
    }

    int lh = 0, rh = 0;

    if (!isBalanced(root->left, lh))
        return false;
    if (!isBalanced(root->right, rh))
        return false;

    height = 1 + max(lh, rh);

    if (abs(lh - rh) > 1)
        return false;

    return true;
}

bool checkAVL(TreeNode *root)
{
    int height = 0;
    return isBalanced(root, height);
}

 bool  areIsomorphicAndAVL(TreeNode* root1, TreeNode* root2){
      return checkAVL(root1) && checkAVL(root2) && isomorphic(root1,root2);
 }

int main(){
    TreeNode* e = new TreeNode(4);
    TreeNode* l = new TreeNode(2);
    l->left = e;
    TreeNode* r = new TreeNode(3);
    TreeNode* root = new TreeNode(1,l,r);

    TreeNode* e1 = new TreeNode(4);
    TreeNode* l1 = new TreeNode(2);
    TreeNode* r1 = new TreeNode(3);
    r1->right = e1;
    TreeNode* root1 = new TreeNode(1,l1,r1);

    cout << areIsomorphicAndAVL(root,root1);

}