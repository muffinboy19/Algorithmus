/*
this code is going to find the peak in the aray 
it will work for both singel nad muliple peaks but there is a conditino no concsecutive elment ares equal */


#include<bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> &arr) {
    // Write your code here


    int n = arr.size();
    if(n==1)return 0;
    if(arr[0]>arr[1])return 0;
    if(arr[n-1]>arr[n-2])return n-1;
    int l =1 ,h = n-2;
    while(l<=h){
        int m = (l+h)/2;
        if(arr[m]>arr[m-1] && arr[m]>arr[m+1])return m;
        else{
            if(arr[m]>arr[m-1]){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
    }
    return -1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}