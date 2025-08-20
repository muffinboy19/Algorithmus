#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* findPredecessor(TreeNode* root) {
  TreeNode* pred = root->left;
  while (pred->right && pred->right != root)
    pred = pred->right;
  return pred;
}

void visit(TreeNode* root, TreeNode*& pred, TreeNode*& x, TreeNode*& y) {
  if (pred && root->val < pred->val) {
    y = root;
    if (x == nullptr)
      x = pred;
  }
  pred = root;
}

void recoverTree(TreeNode* root) {
  TreeNode* pred = nullptr;
  TreeNode* x = nullptr;
  TreeNode* y = nullptr;

  while (root) {
    if (root->left) {
      TreeNode* morrisPred = findPredecessor(root);

      if (morrisPred->right) {
        visit(root, pred, x, y);
        morrisPred->right = nullptr;
        root = root->right;
      } else {
        morrisPred->right = root;
        root = root->left;
      }
    } else {
      visit(root, pred, x, y);
      root = root->right;
    }
  }

  swap(x->val, y->val);
}
