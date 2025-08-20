/*
find the kth missign number */ 

#include<bits/stdc++.h>
using namespace std;
int missingK(vector < int > vec, int n, int k) {
    // Write your code here.


    int l = 0,h=n-1;
    while(l<=h){
        int m = (l+h)/2;
        int missing_m = vec[m] -(m+1);
        if(missing_m<k){
            l = m+1;
        }
        else{
            h = m-1;
        }
    }
    return (l+k);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}