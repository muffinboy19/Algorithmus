/* 
In this quesition 2 starting points are given this is a very good question to solve 

also here you have to maintian the dp of  2 elment and make sure they work together also hence we have to very carefll
very good question 
*/

/*
^ double starting point problem

it requries an 3D array 
so since both of the staring pt would always be at the same row hence we do not need 2 seprate varibl 
to  represent them 

thus if we have overlalp we woul return only the value of one of hte robot and not htye other one otherwise we would alway return the value of b
addtion whne we hit the last row 

we have 3D stoire the value of what can be the max valkue be achieve whne having hte row i and bots at the index j1 and j2 so the real combionat 
is aftyer the index not with it 
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int ish(vector<vector<vector<int>>> &dp,vector<vector<int>>&jj,int i,int j1,int j2){
        if(j1<0 || j2<0 || j1>=jj[0].size() || j2>=jj[0].size()){
            return -1e9;
        }
        if(i==(jj.size()-1)){
            if(j1==j2){
                return jj[i][j1];
            }
            else{
                return jj[i][j1]+jj[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2]; 
        int maxi = INT_MIN;
        // the real reason why here we are required an for of for loop as we need to assign compation 
        // which simnply we cannot do by wring them without using for for loop
        for(int di = -1;di<=1;di++){
            for(int dj =-1;dj<=1;dj++){
                int ans = ish(dp,jj,i+1,j1+di,j2+dj);
                if(j1==j2){
                    ans+=jj[i][j1];
                }
                else{
                    ans+=(jj[i][j1]+jj[i][j2]);
                }
                maxi=max(ans,maxi);
            }
        }
        
        return dp[i][j1][j2]=maxi;
    }
    int solve(int n, int m, vector<vector<int>>& jj) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return ish(dp,jj,0,0,m-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends
