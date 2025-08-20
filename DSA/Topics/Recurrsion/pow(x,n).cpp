/*
^This code contains the optimal approch to the pow functroin 

! actuall logic: 

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
long long power(long long n,long long t){
        if(t == 0){
            return 1;
        }
        if(t % 2 == 0){
            long long key=power(n,t/2)%1000000007;
            return (key%1000000007)*(key%1000000007);
        }
        long long key=power(n,t-1)%1000000007;
        return (key*n)%1000000007;
    }
    double myPow(double x, int n) {
        long double ans = 1.0;
        long long nn = n;
        if(nn<0)nn*=-1;
        while(nn){
            if(nn%2){
                ans = ans*x;
                nn--;
            }
            else{
                x*=x;
                nn/=2;
            }
        }
        if(n<0) ans = (double)(1.0)/(double)ans;
        return ans;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}