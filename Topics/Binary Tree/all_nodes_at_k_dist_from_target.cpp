#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> ans;
    map<TreeNode*, TreeNode*> parent;
    set<TreeNode*> visit;

    // we have to build the parent map firlst 

    void findparnet(TreeNode* node){

        if(!node)return;
        if(node->left){
            parent[node->left] = node;
            findparnet(node->left);
        }
        if(node->right)
        {
            parent[node->right] = node;
            findparnet(node->right);
        }
    }
    // now ew have the parent map 

    // firest dfds from teh traget left n right love the an wid ahve 


    void dfs(TreeNode* node,int k){

        if(!node || visit.count(node))return;

        visit.insert(node);

        if(k==0){
            ans.push_back(node->val);// eact 

            return;
        }
        dfs(node->left,k-1);
        dfs(node->right,k-1);
        dfs(parent[node],k-1); // simply chedcks fothe thing in the other 
        // child sub  tree



    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)return{};
        findparnet(root);
        dfs(target,k);
        return ans;
    }
};
int main(){


}