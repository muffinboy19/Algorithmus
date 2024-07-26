/*
this code finds  out how many times the array is being roated */ 

#include<bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &arr){   

     int l = 0 , h = arr.size()-1;int ans = 100000000; int index = -1;
	 while(l<=h){
		  int  m =( l+h)/2;
		if(arr[l]<=arr[h]){
            if(arr[l] < ans){
                ans = arr[l];
                index = l;
            }
			break;
		}
		 if(arr[l]<=arr[m]){
			 if(arr[l] < ans){
                ans = arr[l];
                index = l;
            }
			 l = m+1;
		 }
		 else{
			 if(arr[m] < ans){
                ans = arr[m];
                index = m;
            }
			 h = m-1;
		 }
	 }

	 return index;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}