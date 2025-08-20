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
    bool func(TreeNode* root,int min,int max){
        if(!root)return true;
        if(root->val < min || root->val > max)return false;
        return func(root->left , min,root->val -1) && func(root->right,root->val+1,max);
    }
    bool isValidBST(TreeNode* root) {
        return func(root);
    }
};