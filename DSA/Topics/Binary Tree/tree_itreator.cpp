#include<bits/stdc++.h>
using namespace std;

 struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        val = val;
        left = nullptr;
        right = nullptr;
    }
};
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    void partialInorder(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* top = s.top();
        s.pop();
        partialInorder(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
int main(){

    return 0;


}