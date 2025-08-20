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
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        if(root==nullptr)return ans;
        while(!q.empty()){

            int level = q.size();
            vector<int> temp;

            for(int i=0;i<level;i++){
                auto it= q.front();
                q.pop();
                temp.push_back(it->val);
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};

int main(){

    return 0;
    
}