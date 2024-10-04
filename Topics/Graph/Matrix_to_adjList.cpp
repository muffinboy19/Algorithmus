// the below code converts the matrix to the adjancey list 


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();  // Number of nodes
        vector<vector<int>> adj(n + 1);  // Initialize adjacency list (1-based index)
        
        // Convert matrix to adjacency list
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && isConnected[i][j] == 1) {
                    adj[i + 1].push_back(j + 1);  // Adjusting for 1-based indexing
                }
            }
        }
        
        // Print the adjacency list
        for (int i = 1; i < adj.size(); ++i) {  // Start from 1
            cout << "Node " << i << ": ";
            for (int j : adj[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
        
        // Additional functionality can be implemented here
        
        return 0;  // Placeholder return value
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}