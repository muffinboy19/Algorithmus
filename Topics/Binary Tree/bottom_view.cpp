/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>>q;
        map<int,int>m;
        
        q.push({root,0});
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            Node* curr =it.first;
            int x = it.second;
            m[x] = curr->data;
            if(curr->left){
                q.push({curr->left,x-1});
            }
            if(curr->right){
                q.push({curr->right,x+1});
            }
        }
        
        vector<int> v;
        for(auto it:m){
            v.push_back(it.second);
        }
        return v;
    }
};