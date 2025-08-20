/*
largest subarray sum minimiseze


here you have to split the array into k subarrays such that the largest sum of the subarry is minimized 

*/


#include<bits/stdc++.h>
using namespace std;
int func(vector<int> &a, int mid){
    int ish = 0 ,osh = 0;
    for(int i = 0 ;i<a.size();i++){
        if(a[i] + ish <= mid){
            ish +=a[i];
        }
        else{
            osh++;
            ish = a[i];
        }
    }

    return osh;
}
int largestSubarraySumMinimized(vector<int> a, int k) {
    // Write Your Code Here

    // if (k > a.size()) {
    //     return -1;
    // }
    int l = *max_element(a.begin(),a.end()),h = accumulate(a.begin(),a.end(),0),ans =a.size();
    while(l<=h){
        int mid = (l+h)/2;
        int  numberofarrays = func(a,mid);
        // if(numberofarrays==k){
        //     ans = min(mid,ans);
        // }
        if(numberofarrays < k){
           h = mid-1;
        }
        else{
            l = mid +1;
        }
    }
    return l;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}


