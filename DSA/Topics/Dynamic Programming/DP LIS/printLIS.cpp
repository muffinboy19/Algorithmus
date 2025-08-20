/*
In this code we are  going to study how to print the LIS of the array 
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        
        //^ creating the dp array first so that subsequece can be printed
        
        vector<int>dp(n,1),hash(n,1); // by default the value should be 1 
        int maxLen  =0;
        int li =0;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j =0;j<i;j++){
                if(arr[j] <arr[i] && dp[i] < 1 + dp[j]){
                    dp[i] = max(dp[i],1 + dp[j]);
                    if(dp[i]>maxLen){
                     li = i;   
                    }
                    maxLen = max(dp[i],maxLen);
                    hash[i] = j;
                }
            }
        }
        // this all was done prevouilyy without the hash array
        /*
        As teh job of the hash array here is to determine weather the 
        last index of the lontgest  subs4e4quce wouled e store 
        */
        //! now simply we are going to find teh larget dp[i] value index
        
        
        // which i already did  in the loop itslef 
        
        vector<int>temp;
        temp.push_back(arr[li]);
        while(hash[li]!=li){
            li = hash[li];
            temp.push_back(arr[li]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends