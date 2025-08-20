

/*
Below we have written the graph in the adjaceny list format in which each node would have vector which would store 
all of its neighbour 
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int v, vector<pair<int,int>>edges) {
        // Code here
        
                int e = edges.size();   
        vector<vector<int>>al(v);

        
        for(int i =0;i<e;i++){
            int fn = edges[i].first;
            int sn = edges[i].second;
            al[fn].push_back(sn);
            al[sn].push_back(fn);
        }
        // for(auto it:al){
        //     for(auto jt:it){
        //         cout<<jt<<" ";
        //     }
        //     cout<<endl;
        // }

        return al;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends