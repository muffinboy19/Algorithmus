/*
helps us to find the minum spannign tree
algo steps
    - sort all the edges ( weight , node 1 , node2 ) so sort wrt to weight then node 1 
    - it checks wethre it belongs  to the same parent or not if yes then  skip else include in the mst

    the main differnce i feel here is that 
    it require all the conept of the disjoint set 

    while the prunes algorithm does not it simply did more work similar to to dijsktra algo
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<int> rank,parent,size;
    void disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUltimateparent(int x){
        if(parent[x] == x)return x;
        return parent[x] = findUltimateparent(parent[x]);
    }
    void joinbysize(int x,int z){
        int ulp_x = findUltimateparent(x);
        int ulp_z = findUltimateparent(z);
        if (ulp_x == ulp_z) return; // Already in the same set
        if(size[ulp_x]> size[ulp_z]){
            parent[ulp_z] = ulp_x;
            size[ulp_x]++;
        }
        else{
            parent[ulp_x] = ulp_z;
            size[ulp_z]++;
        }
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        int n = V;
        disjoint(n);
        vector<pair<int,pair<int,int>>> adjList;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int u = i;
                int v = it[0];
                int weight = it[1];
                adjList.push_back({weight, {u, v}});
            }
        }
        sort(adjList.begin(),adjList.end());
        // nmow i have done sorting now i will create 
        int sum =0;
        // now we have to itrate thorght the edtges 
        
        for(auto it:adjList){
            int u = it.second.first;
            int v = it.second.second;
            int w = it.first;
            if(findUltimateparent(u)!=findUltimateparent(v)){
                sum+=w;
                joinbysize(u,v);
            }
        }
        
        return sum;
    }
};

// * breif : trext to understand waht waas the kruskals algorithym it basically  joined all the nodes after we have sorted thenm 

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