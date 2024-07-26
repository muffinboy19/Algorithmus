/*
this file conatiosn the solution to the number of boyuqes problme 
*/

#include<bits/stdc++.h>
using namespace std;
int func(vector<int> &v,int k,int m,int mid){
	int ish = 0,osh =0 ;
	for(auto it:v){
		if(it<=mid)ish++;
		else {
			osh+=(ish/k);
			ish = 0;
		}
	}
	osh+=(ish/k);
	return osh;
}
int roseGarden(vector<int> arr, int k, int m)
{
	// Write your code here
	int n = arr.size();
	int max_boque = n/k;
	if(max_boque< m)return -1;
	int l = *min_element(arr.begin(),arr.end()),h = *max_element(arr.begin(),arr.end());
	int ans = h;
	while(l<=h){
		int mid = (l+h)/2;
		int nob = func(arr,k,m,mid);
		if(nob< m){
			l = mid+1;
		}
		else{
			ans = min(ans,mid);
			h = mid-1;
		}
	}
	return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}