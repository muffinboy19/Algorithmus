#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void recoverTree(TreeNode* root) {
  TreeNode* prev = nullptr;  // keeps track of the previous node in inorder
  TreeNode* first = nullptr; // first wrong node
  TreeNode* second = nullptr; // second wrong node
  stack<TreeNode*> st;

  while (root != nullptr || !st.empty()) {
    // Traverse to the leftmost node
    while (root != nullptr) {
      st.push(root);
      root = root->left;
    }

    // Process node
    root = st.top();
    st.pop();

    // Check for violations in inorder
    if (prev != nullptr && root->val < prev->val) {
      if (first == nullptr) first = prev; // first time we see the error
      second = root; // update every time we see violation
    }

    prev = root;
    root = root->right;
  }

  // Swap values of the two incorrect nodes
  if (first && second) {
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
  }
}
