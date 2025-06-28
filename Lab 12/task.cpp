#include<iostream>
#include"1.cpp"
using namespace std;

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

// Usage
bool checkAVL(TreeNode *root)
{
    int height = 0;
    return isBalanced(root, height);
}

void inorderT(TreeNode* root,vector<TreeNode*>& vec){
    if(!root) return;
    inorderT(root->left,vec);
    vec.push_back(root);
    inorderT(root->right,vec);
}

void findLR(TreeNode* root,int key,TreeNode*&leftTree,TreeNode*& rightTree){
    vector<TreeNode*> vec;
    inorderT(root,vec);

    for(int i=0; i<vec.size(); i++){
        if(vec[i]->val < key){
            leftTree = vec[i];
        }
        else{
            if(!rightTree){ rightTree = vec[i]; }
            else if(vec[i]->val > rightTree->val) rightTree = vec[i];
        }
    }
}


void splitAVL(TreeNode* root,int key,TreeNode*&leftTree,TreeNode*& rightTree){
     findLR(root,key,leftTree,rightTree);
     if(!checkAVL(leftTree)){
        TreeNode* toAdd = root;
        leftTree = root->left;
        insert(leftTree,toAdd->val);
     }

     if(!checkAVL(rightTree)){
        TreeNode* toAdd = root;
        rightTree = root->right;
        insert(rightTree,toAdd->val);
     }
}

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){
   vector<int> v ={10,5,15,2,7,20};
   TreeNode* root = new TreeNode(v[0]);
   for(auto i:v){
     root = insert(root,i);
   }
   inorder(root);
   cout << endl;
   TreeNode* l;
   TreeNode* r;
   splitAVL(root,10,l,r);
   inorder(l);
   cout << endl;
   inorder(r);
   cout << endl;
}