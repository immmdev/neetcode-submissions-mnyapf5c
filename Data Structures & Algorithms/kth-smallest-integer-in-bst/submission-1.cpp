class Solution {
public:
    void inorder(TreeNode* root,int &ans,int &k){
        // inorder is always sorted
        if(root==NULL) return;
        inorder(root->left,ans,k);
        if(k!=0){
            ans=root->val;
            k--;
        }
        inorder(root->right,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int n=k;
        inorder(root,ans,n);
        return ans;
    }
};