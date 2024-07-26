/*
this code is about finding the minmum in the roated sorted array 

*/


#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr)
{
	  int l = 0 , h = arr.size()-1, ans = INT_MAX;
	 while(l<=h){
		  int  m =( l+h)/2;
		if(arr[l]<=arr[h]){
			ans = min(ans,arr[l]);
			break;
		}
		 if(arr[l]<=arr[m]){
			 ans = min(ans,arr[l]);
			 l = m+1;
		 }
		 else{
			 ans = min(ans,arr[m]);
			 h = m-1;
		 }
	 }

	 return ans;


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}