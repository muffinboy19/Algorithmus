/*
In the prevous question we had ony limted paramerts and contion to achive from now we have teh numbdr of 
condition as dynamic thus 
This is a better question 



^Frog jump  with k steps



did this myself on first attempt 

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        
        int n = arr.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int i = 1;i<n;i++){
            int jumpCost =INT_MAX;
            for(int j =1;j<=k;j++){
                if(i-j>=0){
                    int bi = dp[i-j] + (abs(arr[i]-arr[i-j]));
                    jumpCost = min(jumpCost,bi);
                }
            }
            dp[i]= jumpCost;
        }
        
        return dp[n-1];
        
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends