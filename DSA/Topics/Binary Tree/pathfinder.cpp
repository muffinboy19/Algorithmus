#include<bits/stdc++.h>
using namespace std;
bool pathfinder(TreeNode* root, TreeNode* target, vector<int>& path) {
    if (!root) return false;

    // Add current node to path
    path.push_back(root->val);

    // Check if current node is the target
    if (root == target)
        return true;

    // Search left and right subtrees
    if (pathfinder(root->left, target, path) || pathfinder(root->right, target, path))
        return true;

    // Backtrack if target not found in this path
    path.pop_back();
    return false;
}

int main(){


}