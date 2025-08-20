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
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> v;
        stack<TreeNode*> st1,st2;
        if(root==nullptr)return v;
        st1.push(root);
        while(!st1.empty()){

            root  = st1.top();
            st1.pop();


            st2.push(root);
            if(root->left)st1.push(root->left); // here lft  is on top bc when it goies to tck 
            // it will got r l then when we will pyll from the st2 we will pull l r an r l would be pused 
            if(root->right)st1.push(root->right);
        }


        while(!st2.empty()){


            v.push_back(st2.top()->val);
            st2.pop();
        }
        return v;

        
    }
};
int main(){

    return 0;
}