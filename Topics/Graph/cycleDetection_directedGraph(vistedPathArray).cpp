/*/
in this code we are going to write the code for cycle detction 
in a directed graph

jsort of modifed dfs search
*/
/*(
declare 2 aray vis , pathVis 

then check for dfs
in the dfs 
first mark vis and pathVis = 1 
tehn in the dfs loop 
    check if the it gives true
    if yes then return tru7e;
    else checkif the pathVis is 1 
    then return true;

    else aoutside tehfoor loop 
    make the pathVis 0 again 
    return false;`
)*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&pvis,vector<vector<int>>&adj,stack<int>&st){
        vis[node]=1;
        pvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pvis,adj,st)){
                    return true;
                }
            }
            else if(pvis[it]){
                return true;
            }
        }
        pvis[node]=0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pr) {
        int v = numCourses;
        vector<int>vis(v),pvis(v);
        vector<vector<int>>adj(v,vector<int>());
        for(auto it:pr){
            adj[it[1]].push_back(it[0]);
        }
        stack<int>st;
        vector<int>topo;
        for(int i=0;i<v;i++){
            // i will check with first that vis
            if(!vis[i]){
                if(dfs(i,vis,pvis,adj,st)){
                    topo.clear();return topo;
                }
            }
        }

        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}