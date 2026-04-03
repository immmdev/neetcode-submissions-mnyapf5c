/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int depth(TreeNode* root,int &maxDif){
        if(root==NULL) return 0;
        int l=depth(root->left,maxDif);
        int r=depth(root->right,maxDif);
        maxDif=max(abs(l-r),maxDif);
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        int maxDif=0;
        depth(root,maxDif);
        if(maxDif>1) return false;
        return true;
    }
};
