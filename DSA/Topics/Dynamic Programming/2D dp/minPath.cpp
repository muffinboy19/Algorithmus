/*
This problem only have one thing diffrent that there is full tow with a base conditon intates of lnly one point  
henc  it have sliigt differnt code 
also in this the memoztio ndo not work only the 
the  tabulaion works 

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& jj) {
        int n = jj.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[0][i] = jj[0][i];
        }
        for(int i = 1;i<n;i++){
            for(int j =0;j<n;j++){
                int d = jj[i][j]+((i>0)?dp[i-1][j]:1e9);
                int dl = jj[i][j]+((i>0 && j>0)?dp[i-1][j-1]:1e9);
                int dr = jj[i][j]+((i>0 && j<jj.size()-1)?dp[i-1][j+1]:1e9);
                dp[i][j] = min(d,min(dl,dr));

            }
        }

        int to = INT_MAX;
        for(int i=0;i<n;i++){
            to=min(to,dp[n-1][i]);
        }
        return to;
        
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}