#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode
{
    string val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(string x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(string x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool insert(TreeNode* root,string value)
{
    if (!root)
    {
        return false;
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

TreeNode* wordsToBST(const vector<string>& words){
    int size=words.size();
    if(size==0) return nullptr;
    TreeNode* root = new TreeNode(words[0]);
    for(int i=1; i<size; i++){
       bool ans = insert(root,words[i]);
       if(ans==0) cout << "Can't insert " << words[i] << endl;
    }
    return root;
}

void preOrder(TreeNode* root){
    if(!root) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}


bool anyFind(string s1,const string& s2){
    int size = s2.length();

    for(int i=0; i<size; i++){
        if(s1[i]!=s2[i]) return false;
    }

    return true;
}

void search(TreeNode *root,const string& prefix,vector<string>& ans)
{
    if(!root) return;

    bool result = anyFind(root->val,prefix);
    if(result) ans.push_back(root->val);
    search(root->left,prefix,ans);
    search(root->right,prefix,ans);
}



vector<string> autoComplete(TreeNode* root,const string& prefix){
     vector<string> ans;
     search(root,prefix,ans);
     return ans;
}

int main(){
    vector<string> x = {"dog", "deer", "deal", "doom", "dove"};

    TreeNode* root = wordsToBST(x);

    // preOrder(root);
    // cout << endl;

    vector<string> a=autoComplete(root,"do");

    for(auto i:a){
        cout << i << " ";
    }
}