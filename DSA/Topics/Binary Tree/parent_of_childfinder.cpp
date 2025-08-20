#include<bits/stdc++.h>
using namespace std;
TreeNode* func(TreeNode* root, TreeNode* t, vector<TreeNode*>& v) {
    if (!root) return nullptr;
    if (root == t) return root;

    TreeNode* left = func(root->left, t, v);
    TreeNode* right = func(root->right, t, v);

    if (left == t || right == t) {
        v.push_back(root);  // `root` is the parent of `t`
        return root;        // or return `t`, depending on use case
    }

    return nullptr;
}

int main(){


}