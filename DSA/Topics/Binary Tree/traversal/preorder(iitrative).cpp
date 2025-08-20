#include<bits/stdc++.h>
using namespace std;
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> pre;
        if(root==nullptr)return pre;
        st.push(root);
        while(!st.empty()){
            root= st.top();
            st.pop();
            pre.push_back(root->val);
            if(root->left)st.push(root->left);
            if(root->right)st.push(root->right);

        }

        return pre;

        
    }
};

int main(){
    return 0;
    
}