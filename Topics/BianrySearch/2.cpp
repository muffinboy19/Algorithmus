/*
this lecture is about lowerbound and upperbound 
*/ 


#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> arr, int n, int x) {
	int l = 0 , h = n-1,ans= n;
	while(l<=h){
		int m= ( l+h)/2;
		if(arr[m]>=x){
			ans = m;
			h = m-1;
		}
		else{
			l = m+1;
		}
	}
	return ans;
}


int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	

	int l = 0 , h = n-1,ans= n;
	while(l<=h){
		int m = (l+h)/2;
		if(arr[m]>x){
			ans = m;
			h = m-1;
		}
		else{
			l = m+1;
		}
	}

	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
    the above funtion  implemnts the lower bound  and the upperbound both here */
    

    return 0;
}



#include<bits/stdc++.h>
using namespace std;
int insertSearchPlace(vector<int> arr, int n, int x) {
	int l = 0 , h = n-1,ans= n;
	while(l<=h){
		int m= ( l+h)/2;
		if(arr[m]>=x){
			ans = m;
			h = m-1;
		}
		else{
			l = m+1;
		}
	}
	return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
    also to search and isert the index if the elmetn is presnt give its index this would be solved by the 
    Lower_bound itself */

    return 0;
}


