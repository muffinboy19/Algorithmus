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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        queue<pair<Node*,int>>q;
        map<int,int> m;
        q.push({root,0});
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            Node* curr = it.first;
            int x = it.second;
            if(m.find(x)==m.end()){
                
                // when its empty 
                
                m[x] = curr->data;
            }
            if(curr->left){
                q.push({curr->left,x-1});
            }
            if(curr->right){
                q.push({curr->right,x+1});
            }
            
        }
        
        vector<int> ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};