/*
This is quesiton is done on a unidrectd graph whyich is connected means 
no island 


there are many impmentation of it 
1 using set
2. using a pq  also 
3. using queue ( pls solve this one ) 
    also know the diff that why we are not using a queue n why a pq


    why the stament that dijkstar algo requies a minimum heap structure

    a min heap is entirely new data structer used and implementted by 
    pq 

    example:;:: 


    #include <queue>
#include <vector>

std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // Min-heap


by defalyt a pq is a max heap to use it ias a min heap we have to use the above line for it 


this is the noermal one i feel 

*/

 // this one is eimplenmt using pq ;


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
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(n,1e9);
        dis[src] = 0;
        pq.push({0,src});
        
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            int weight = pq.top().first;
            
            pq.pop(); // vbery imp step 
            
            for(auto it:adj[node]){
  
                    int next =  it.first;
                    int edgeWeight = it.second;
                    
                    if(weight+ edgeWeight < dis[next]){
                        dis[next] = weight+ edgeWeight;
                        pq.push({dis[next],next});
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

