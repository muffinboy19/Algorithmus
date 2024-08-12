/*
In this method we return 1 to count all the possible ways 
*/  

#include<bits/stdc++.h>
using namespace std;
void ish(int n ){
    if(n==0)return 1;
    if(n==1)return 1;
    int right = ish(n-1);
    int left = ish(n-2);
    return right + left ;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}

//  ^ below we convert this to to tabluation / dp format 

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }

           return dp[n];
    }
};