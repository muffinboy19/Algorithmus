#include<bist/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val){
        val = val;
        left = right = nullptr;
    }
};
void func(Node* root){
    queue<Node*> q;
    vector<vector<int>>ans;
    vector<int> ans;
    if(!root)return ans;
    q.push(root);
    bool flag = false;
    while (!q.empty())
    {
        int x = q.size();
        vector<int> v;
        for(int i=0;i<x;i++){
            auto it= q.front();
            v.push_back(it->val);
            if(it->left){
                q.push(it->left);
            }
            if(it->right){
                q.push(it->right);
            }
        }

        if(flag == true){
            reverse(v.begin(),v.end());
            flag = false;
        }
        else{
            flag = true;
        }
        ans.push_back(v);
    }
}
int main(){


}