#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:

    void preorder(TreeNode* curr,vector<int>&v){
        if(curr==nullptr)return;
        v.push_back(curr->val);
        preorder(curr->left,v);
        preorder(curr->right,v);
        return;
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int>v;
        preorder(root,v);
        return v;

    }


};