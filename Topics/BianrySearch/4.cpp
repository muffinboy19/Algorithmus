/*
Search in  a rotated sorted array  
where the array one side might not be entrly sorted 
*/
#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int l = 0 , h = n-1;
    while(l<=h){
        int m = (l+h)/2;
        if(arr[m]==k){
            return m;
        }

        if(arr[l]<=arr[m]){

            if(arr[l]<=k && k<=arr[m]){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        else{
            if(arr[m]<=k && k<=arr[h]){
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

