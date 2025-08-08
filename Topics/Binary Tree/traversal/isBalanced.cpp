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
    int func(TreeNode* curr){
        if(curr==nullptr)return 0;
        int l = func(curr->left);
        int r = func(curr->right);
        return 1+ max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        map<int,int> m ; // node number , distacee from the root .
        
    }
};