/*
This is a simple question were wse have learned to check if the subset has the sum 
k or not 
*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool ish(vector<int>&jj,int i,int tt,vector<vector<int>>&dp){
        if(i==0){return jj[i]==tt;}
        if(tt==0)return true;
        if(dp[i][tt]!=-1)return dp[i][tt];
        bool  nopick = ish(jj,i-1,tt,dp);
        bool pick=false;
       if(jj[i]<=tt){
            pick = ish(jj,i-1,tt-jj[i],dp);
       }
        return dp[i][tt] = pick||nopick;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return ish(arr,arr.size()-1,sum,dp);
    }
};

        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends