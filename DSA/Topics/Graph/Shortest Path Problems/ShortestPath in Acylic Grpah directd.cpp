/*
This tiem the grpah is acylice so we hve to irteate thorgh all index
also since this time there is weight we will istead of doidng dis+ 1 
will do dis+ widht 
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void topoSort(int node,vector<int> & vis,vector<pair<int,int>> adjList[],int n,stack<int>&st){
        vis[node] =1;
        
        for(auto it:adjList[node]){
            if(!vis[it.first])topoSort(it.first,vis,adjList,n,st);
        }
        st.push(node);
        
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        // code here
        int n = V;
        vector<pair<int,int>>adjList[n];
        for(auto it:edges){
            adjList[it[0]].push_back({it[1],it[2]});
        }
        stack<int> st;
        vector<int>vis(n);
        for(int i=0;i<n;i++)vis[i] = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topoSort(i,vis,adjList,n,st);
            }
        }
        vector<int>dis(n);
        for(int i=0;i<n;i++){
            dis[i] = 1e9;
        }
        dis[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it:adjList[node]){
                int next = it.first;
                int weight = it.second;
                if(dis[node] + weight < dis[next]){
                    dis[next] = dis[node] + weight;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(dis[i]==1e9){
                dis[i] =-1;
            }
        }
        
        // there is not pusihng back again into the stack
        return dis;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends