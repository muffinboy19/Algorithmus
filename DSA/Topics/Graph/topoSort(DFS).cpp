// htere i ma going to write hyte stpe sof topo sort using (DFS)

/*

create a visited arary 
crate a stack 
itreate throught 1 to V ( number of nodes)

in which call teh dfs funciton 

there
mark as visited 
the traversal throght the adj list and then again do the dfds
at the end off the for loop
push the node into the stack 

pop the stack one by one and fill the vector
return ans ;
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,st,adj);
            }
        }
        st.push(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pr) {
        // i do not think this code is of cycle detection 
        int v = numCourses;
        vector<vector<int>>adj(v,vector<int>());;
        for(auto it:pr){
            adj[it[0]].push_back(it[1]);
        }
        for(auto it:adj){
            for(auto jt:it){
                cout<<jt<<" ";
            }
            cout<<endl;
        }cout<<endl;
        vector<int>vis(v,0);
        stack<int>st;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        // here my ans was comming revesr 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}