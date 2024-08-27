/*
In The below code we will split the array in 2 
parts and find a specific difference of it,
*/
/*
this question is bye count target sum  method only 

as 
s1-s2 = d 
thene we substiute t = s1 + s2 ;
hence we get s1 = (d+t/2)

thus by finding the above sub set with the above sum we have found what we want in this quesiton 
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum =0;
        for(aut)
        vector<vector<int>>dp(n,vector<int>())
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends   ABOVE IS THE MEMOSIZAITON APPROCH OF countSbuset