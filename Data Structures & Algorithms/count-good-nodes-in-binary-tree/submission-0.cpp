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
    int cntGoodNodes(TreeNode* root,int maxVal){
        if(root==NULL)return 0;
        int res=root->val>=maxVal?1:0;
        maxVal=max(maxVal,root->val);
        res+=cntGoodNodes(root->left,maxVal);
        res+=cntGoodNodes(root->right,maxVal);
        return res;
    }
    int goodNodes(TreeNode* root) {
       return cntGoodNodes(root,root->val);
    }
};
