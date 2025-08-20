#include<bits/stdc++.h>
using namespace std;


int timer = 1;

void dfs(int node , int parent)
vector<vector<int>> criticalConnections(int n,vector<vector<int>>&connections){

    vector<int> adj[n];

    for(auto it: connections){

        int u = it[0],v = it[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n,0);

    int tin[n]; // timer array 
    int low[n];// lower arary 
    vector<vector<int>> bridges;

    dfs(0,-1,vis,adj,tin,low,bridges);
    return bridges;
}

int main(){


}