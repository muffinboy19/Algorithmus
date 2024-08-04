//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string> v  = {"0","1"};    
        if(num==1){
            return v;
        }
        int i =2,j=0;
        while(i<=num){
            vector<string> ans;
            for(auto it: v){
                ans.push_back(it+"0");
                if(it[it.size()-1]=='1'){
                    continue;
                }
                else{
                    ans.push_back(it+"1");
                }
            }
            v=ans;
            i++;
        }
        
        // for(auto it:v){cout<<it<<" ";}cout<<endl;
        return v;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends