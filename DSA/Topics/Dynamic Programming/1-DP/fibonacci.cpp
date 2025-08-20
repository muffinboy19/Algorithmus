/*
here there are going to be 3 solutions to per question 
& Fibonacci serires 
*/


// ! this Method is called Memoization   (top down) 
#include<bits/stdc++.h>
using namespace std;
int f(int n,vector<int> &dp){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];

    return dp[n] = f(n-1,dp) + f(n-2,dp);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin>>n;
    vector<int> dp(n+1,-1);
    cout<<f(n,dp);
    
    /*
    tc o(n)
    sc o(n) + o(n)
       one for the recurrsion stack space and one for the vector 
       
    */

    return 0;
}


/* how to convert a memoizatiron to a tabulation 

(bottom up)
try to go from the base case to the top

step 1 : 
intialise the base cases 
exaple here dp[0] = 0 and dp[1]=1

step 2: 
use the same relation in a for loop in the main() code only 
example dp[i] = dp[i-1] + dp[i-2];

*/


/*
the below is the most optimal code one step further than tabluation i assume 
& tabluation or most optimal code   (bottom up)
*/


#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ;cin>>n;
    int p2 = 0;
    int p1 = 1;
    for(int i = 2;i<=n;i++){
        int cur = p2+p1;
        p2 = p1;
        p1 = cur;
    }

    cout<<(p1%(1000000007))<<endl;
    

    return 0;
}