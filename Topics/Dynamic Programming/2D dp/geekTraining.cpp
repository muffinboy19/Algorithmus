/*
This is the first quesitno of 2D dp 

*/

/* 

!!The main thing i forget while sovling this quesiont was that 
!! the current value was the clumi9natifve sum of the prev and teh current logic 
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int ish(int day , int last , vector<vector<int>> &a,vector<vector<int>>&dp){
        if(dp[day][last]!=-1)return dp[day][last];
        
        if(day==0){
            int maxi = 0;
            for(int i =0;i<=2;i++){
                if(i!=last){
                    maxi=max(maxi,a[0][i]);
                }
            }
            return dp[day][last]=maxi;
        }
        int maxi = 0;
        for(int i =0;i<=2;i++){
            if(i!=last){
                int act = a[day][i] + ish(day-1,i,a,dp);
                maxi= max(maxi,act);
            }
        }
        
        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(4,-1));
        
        return ish(n-1,3,arr,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

//^ THE ABOVE IS RECURSION DP SOLUTION 



