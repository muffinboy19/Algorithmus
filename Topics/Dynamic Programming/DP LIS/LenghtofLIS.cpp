/*
In this we code we would study on how to count hte lenght of hte lis 
here we are oging to use 2 pointer aprooch and also sicne we will make one pointer at -1 hence 
we will use coordinate shift to acess  diffrent operaions 
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ish(vector<vector<int>>&dp,vector<int>&a,int pi,int i){
        if(i==a.size()){
            return 0;
        }
        if(dp[i][pi+1]!=-1)return dp[i][pi+1];
        int take  = 0 ;
        int notake = ish(dp,a,pi,i+1);
        if(pi==-1||a[pi]<a[i] ){
            take =  1 + ish(dp,a,i,i+1);
        }
        return dp[i][pi+1] = max(take,notake);

    }
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return  ish(dp,a,-1,0);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}