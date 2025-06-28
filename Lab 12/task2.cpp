#include <iostream>
using namespace std;
#include "BST.cpp"
#include <queue>

int countl(TreeNode *root)
{
    queue<pair<TreeNode *, int>> q;
    vector<pair<TreeNode *, int>> vec;
    q.push({root, 0});

    int mxl = 0;
    while (!q.empty())
    {
        auto [curr, l] = q.front();
        vec.push_back(q.front());
        mxl = max(mxl, l);
        q.pop();
        if (curr->left)
            q.push({curr->left, l + 1});
        if (curr->right)
            q.push({curr->right, l + 1});
    }

    vector<bool> v(mxl+1,true);

    for (int i = 0; i < vec.size(); i++)
    {
        auto [curr, l] = vec[i];
        if (!curr->left && !curr->right)
        {
            v[l] = false;
        }
        if (curr->left && curr->right)
        {
            v[l] = false;
        }
    }
    
    int ans=0;
    for(int i=0; i<v.size()-1; i++){
        ans += v[i];
    }

    return ans;
}

int countCompressionLevels(TreeNode *root)
{

    return countl(root);
}

int main(){
  vector<int> i ={10,5,15,6,20};
  TreeNode* root = new TreeNode(i[0]);
  for(int j=1; j<i.size(); j++){
    insert(root,i[j]);
  }

  cout << countCompressionLevels(root);
}