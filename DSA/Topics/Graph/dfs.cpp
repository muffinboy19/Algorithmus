//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void traversal(int cn,int vis[],vector<int>&dfs,vector<int> adj[]){
        vis[cn] =1;
        dfs.push_back(cn);
        for(auto it:adj[cn]){
            if(!vis[it]){
                traversal(it,vis,dfs,adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        int vis[V]={0};
        vector<int> dfs;
        vis[0]=1;
        traversal(0,vis,dfs,adj);
        return dfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends