/*(
Algrothim for the Question:

here the edge wieght is 1   \
u would be given the adjancey list 

we will use a plain BFS algorithm 
we will use a stack 
we will use a distance array/ vector


simple store the nodes ditance in the queue , thene 
check for htequeue not empty 
do the preocess again update the distance vector 


*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        int n = N;
        int m = M;
        
        vector<int> adj[n]; 
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }
        // for(auto it:adj){
        //     // cout<<it<<"(("<<" ";
        //     for(auto jt:it){
        //         cout<<jt<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int>dis(n);
        queue<pair<int,int>>q;
        for(auto &it:dis){
            it= INT_MAX;
        }
        dis[src]=0;
        q.push({src,0});
        
        while(!q.empty()){
            
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            for(auto it: adj[node]){
                if(dist+1 < dis[it]){
                    dis[it] = dist + 1;
                    q.push({it,dist+1});
                }
            }
        }
        
        for(auto &it:dis){
            if(it==INT_MAX){
                it=-1;
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends