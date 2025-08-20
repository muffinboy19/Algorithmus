/*
Here in this code we are going to */


// Merge Sorted Array

/*
The below soring algorhimg allowws us to sort 2 sepratre arrays wihtout using extra space
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int n,m;
    cin>>n>>m;
    int a1[n],a2[m];
    for(int i=0;i<(n+m);i++){
        if(i<n)cin>>a1[i];
        else cin>>a2[n-i];
    }

    int gap = ( n+m)/2 + ( n+m)%2; // this last part will make sure it stays alwasy even;
    while(gap>0){
        int left = 0, right = left+ gap;
        while(right < (n+m)){

        }
    }

    return 0;
}