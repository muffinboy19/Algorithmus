/*
^this code is used count the distinct subsequesin in a string using recursion 
!this code is very tough and needs to leanred by u 
*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int ff(string s){
        unordered_map<char,int> last;
        int count = 1;
        for(auto it:s){
            int nc = count*2;
            
            if(last.find(it)!=last.end()){
                nc -=last[it];
        
            }
            last[it]=count;
            count = nc;
        }
        return count;
    }
    string betterString(string str1, string str2) {
        return ff(str2)>ff(str1) ? str2:str1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends