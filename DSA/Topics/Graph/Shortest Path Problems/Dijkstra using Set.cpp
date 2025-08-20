/*
This one is implemented using a set 
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
        set<pair<int,int>> s;
        s.insert({0,src});
        vector<int> dis(n,1e9);
        dis[src] = 0;
        while(!s.empty()){
            
            // first we have to create a front pointer in a set 
            auto jj  = *(s.begin()); // * as we need the value of it not hte pointer 
            int node = jj.second;
            int weight = jj.first;
            
            s.erase({weight,node});
            for(auto it:adj[node]){
                int next = it.first;
                int edgeWeight = it.second;
                
                
                if(weight+edgeWeight < dis[next]){
                    if(edgeWeight!=1e9){
                        s.erase({dis[next],next});
                    }
                    dis[next]  = weight + edgeWeight;
                    s.insert({dis[next],next});
                    
                }
            }
            
        }
        return dis;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends 


// time complexisty is ElogV

we do not use queu becuse  it casues unncssaytr occurance in the heap 
which at the end leads to no change.. 
