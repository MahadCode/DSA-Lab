#include"BST.cpp"
#include<vector>

int kthMost(TreeNode* root,int& k){
    if(!root) return -1;

    int rightVal = kthMost(root->right,k);
    if(rightVal!=-1){
        return rightVal;
    }
    
    k--;
    if(k==0){
        return root->val;
    }

    return kthMost(root->left,k);
}


int kthMostViewedPost(TreeNode* root, int k) {
    return kthMost(root,k);
}

int main(){
    vector<int> a={50,30,70,20,40,60,80};
    
    TreeNode* root = new TreeNode(a[0]);

    for(int i=1; i<a.size(); i++){
        insert(root,a[i]);
    }

    cout << kthMostViewedPost(root,6);
}