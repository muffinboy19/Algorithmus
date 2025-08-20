#include <bits/stdc++.h>
using namespace std;

// TreeNode is assumed to be already defined as:
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:


    bool dfs(TreeNode* node, long lo, long hi, unordered_map<int, TreeNode*>& rootMap) {
        if (!node) return true;
        if (node->val <= lo || node->val >= hi) return false;

        // If it's a leaf that matches another tree, merge it
        if (!node->left && !node->right && rootMap.count(node->val)) {
            TreeNode* sub = rootMap[node->val];
            rootMap.erase(node->val);
            node->left = sub->left;
            node->right = sub->right;
        }

        return dfs(node->left, lo, node->val, rootMap) && dfs(node->right, node->val, hi, rootMap);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> rootMap;
        unordered_set<int> leafVals;

        // Step 1: Build maps
        for (TreeNode* tree : trees) {
            rootMap[tree->val] = tree;
            if (tree->left) leafVals.insert(tree->left->val);
            if (tree->right) leafVals.insert(tree->right->val);
        }

        // Step 2: Find the main root (not in any leaves)
        TreeNode* root = nullptr;
        for (TreeNode* tree : trees) {
            if (!leafVals.count(tree->val)) {
                root = tree;
                break;
            }
        }
        if (!root) return nullptr;

        rootMap.erase(root->val);

        // Step 3: DFS merge + BST check using separate function
        if (!dfs(root, LONG_MIN, LONG_MAX, rootMap)) return nullptr;

        return rootMap.empty() ? root : nullptr;
    }


    
};
