#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) {
        val = v;
        left = right = nullptr;
    }
};

TreeNode* first = nullptr;
TreeNode* second = nullptr;
TreeNode* prevNode = nullptr;

void inorder(TreeNode* node) {
    if (node == nullptr) return;

    inorder(node->left);

    // Detect swapped nodes
    if (prevNode != nullptr && prevNode->val > node->val) {
        if (first == nullptr) first = prevNode;
        second = node;
    }

    prevNode = node;

    inorder(node->right);
}

void recoverTree(TreeNode* root) {
    first = second = prevNode = nullptr;
    inorder(root);

    if (first && second) {
        swap(first->val, second->val);
    }
}



/// 