/*
here we require a 
priotiy_queue a min heap structure
visted arary 
sum =0*
a mast list 
pq contains { ditnce node parrent} 


basically isa a greeduy algortihoikm only 



*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    
    // here we have to find eh mst
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        
        
        // from  the adj list we get that it is a undirectet graph
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> vis(V,0);
        // vis[0] = 1;
        int sum =0;
        while(!pq.empty()){
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            if(vis[node])continue;
            vis[node] = 1;
            sum+=weight;
            for(auto it:adj[node]){
                int next = it[0];
                int newweight = it[1];
                if(!vis[next]){
                    pq.push({it[1],it[0]});
                }
            }
        }
        return sum;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends