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
    vector<int> inorderTraversal(TreeNode* root) {

        stack<TreeNode*>st;
        vector<int> io;
        TreeNode* curr = root;
        while(true){


            if(curr!=nullptr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                if(st.empty())break;
                curr = st.top();
                st.pop();
                io.push_back(curr->val);
                curr=curr->right;
            }
        }

        return io;
        
    }
};

int main(){


}