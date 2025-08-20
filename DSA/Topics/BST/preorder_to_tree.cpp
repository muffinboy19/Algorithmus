#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

TreeNode* buildBSTFromPreorder(const vector<int>& preorder) {
    TreeNode* root = nullptr;

    for (int value : preorder) {
        root = insert(root, value);
    }

    return root;
}

int main() {
    vector<int> preorder = {10, 5, 1, 7, 40, 50};

    TreeNode* root = buildBSTFromPreorder(preorder);

    cout << "Inorder traversal of constructed BST: ";


    return 0;
}
