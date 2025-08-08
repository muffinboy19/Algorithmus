#include<bits/stdc++.h>
using namespace std;
int main(){

    
}

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
    vector<int> postorderTraversal(TreeNode* root) {
        // this time we have to use only one stack
        stack<TreeNode*> st;
        vector<int> v;
        st.push(root);
        if(root==nullptr)return v;
        while(!st.empty()){
            root  = st.top();
            st.pop();
            v.push_back(root->val);

            if(root->left)st.push(root->left);
            if(root->right)st.push(root->right);
            
        }

        reverse(v.begin(),v.end());
        return v;
        
    }
};