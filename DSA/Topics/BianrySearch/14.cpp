/*
this code is goign to tell  you about the thres hold quetsion */ 

#include<bits/stdc++.h>
using namespace std;
int func(vector<int> &arr,int m){
	int thres = 0 ;
	for(auto it:arr){
		thres+= (ceil((double)it/(double)m));
	}
	return thres;
}


int smallestDivisor(vector<int>& arr, int limit)
{
	// Write your code here.


	// the max value of hte alhpah can be thhe max elmetns of hte array 
	// when alpha = max value thres == n 
	// when the alpha = 1 thres == sum  of array 
	/*

	so our taask is to find smallest value fo the alpha so that the thres is smaller than the limit 

	1 2 3 4 5 ... max(numter) 
	sum . .. .. .. .n 


	so the alpha would lie between ( 1 to maxI(number));
	while the thres should lie between n and sum 
	*/

	int ish = 0 , osh = 0;
	for(auto it:arr){
		ish+=it;
		osh = max(osh,it);
	}

	int l = 1 , h = osh;
	while(l<=h){
		int m = (l+h)/2;
		int thres_m = func(arr,m);

		if(thres_m <= limit){
			h = m-1;
		}
		else{
			l = m+1;
		}


	}
	return l;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}