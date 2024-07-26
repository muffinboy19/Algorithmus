/*
this file contains the most optimized solution 

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int  n;cin>>n;
    long long int  prev2=0,prev=1;
    for(int i=2;i<=n;i++){
        long long int  curi = prev+prev2;
        prev2 =prev;
        prev=curi;
    }
    cout<<prev<<endl;
    

    return 0;
}