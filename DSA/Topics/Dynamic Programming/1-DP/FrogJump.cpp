/*
In this question we made the value return only 0 as we had a seprate entity to retunr / manage wiht it 
thus this is good example on manuplation for small steps 

example here we only jump of 2 entity thus they could be written in a single loop

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        
        vector<int> dp(n+1,-1);
        dp[0]=0;
        for(int i =1;i<=n;i++){
            int jumpTwo = INT_MAX;
            int jumpOne = dp[i-1]+(abs(height[i]-height[i-1]));
            if(i>1){
                jumpTwo = dp[i-2]+(abs(height[i]-height[i-2]));
            }
            dp[i] = min(jumpTwo,jumpOne);
        }
        return dp[n-1];
        
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
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends