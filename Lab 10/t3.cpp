#include"BST.cpp"
#include<vector>

void btPaths(TreeNode* root,int targetSum,vector<int>& a,bool& ans){
    if(!root) return;
    a.push_back(root->val);

    //hiting a leaf
    if(!root->left && !root->right){
       bool run=false;
       int sum=0;
       for(auto i: a){
        run=true;
        sum += i;
       }
       if(sum==targetSum && run)  ans = true;
    }

    btPaths(root->left,targetSum,a,ans);
    btPaths(root->right,targetSum,a,ans);

    a.pop_back();
}


bool hasPathSum(TreeNode* root,int targetSum){
    vector<int> a;
    bool ans=false;
    btPaths(root,targetSum,a,ans);
    return ans;
}

void setNode(TreeNode* rt,TreeNode* l,TreeNode* r){
    rt->left=l;
    rt->right=r;
}



int main(){
    vector<int> x1={5,4,8,11,13,4,7,2};
    TreeNode* root=new TreeNode(x1[0]);
    TreeNode* l11=new TreeNode(x1[1]);
    TreeNode* l12=new TreeNode(x1[2]);
    TreeNode* l21=new TreeNode(x1[3]);
    TreeNode* l22=new TreeNode(x1[4]);
    TreeNode* l23=new TreeNode(x1[5]);
    TreeNode* l24=new TreeNode(x1[6]);
    TreeNode* l25=new TreeNode(x1[7]);
    setNode(root,l11,l12);
    setNode(l11,l21,nullptr);
    setNode(l12,l22,l23);
    setNode(l21,l24,l25);

    preOrder(root);
    
    cout << endl;

    cout << hasPathSum(root,26);

}