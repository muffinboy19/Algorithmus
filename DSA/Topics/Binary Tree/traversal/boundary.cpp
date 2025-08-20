/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

bool isleaf(Node* root){
    return root->left==NULL && root->right==NULL;
}

void rc(Node* root,vector<int>&v){
    Node*curr=root->right;
    vector<int>tt;
    if(!curr || isleaf(curr))return;
    while(curr){
        
        if(!isleaf(curr)){
            tt.push_back(curr->data); 
        }
        if(curr->right){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    
    reverse(tt.begin(),tt.end());
    for(auto it:tt)v.push_back(it);
    
}
void lc(Node* root,vector<int>&v){
    
    
    
    Node*curr = root->left;
    if(!curr || isleaf(curr))return;
    
    while(curr){
        if(!isleaf(curr))v.push_back(curr->data);
        if(curr->left){
            curr= curr->left;
        }
        else {
            curr = curr->right;
        }
    }
}
void leaf(Node* root,vector<int>&v){
    if(!root)return;
    
    if(isleaf(root))v.push_back(root->data);
    
    leaf(root->left,v);
    leaf(root->right,v);
}
class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(!root)return {};
        vector<int>v;
        if(!isleaf(root))v.push_back(root->data);
        lc(root,v);
        leaf(root,v);
        
        rc(root,v);
        
        
       
        return v;
        
    }
};













