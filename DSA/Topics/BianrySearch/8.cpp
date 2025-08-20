/*
this code is going  to tell you how to find a elmetnw when al lthe gin ven elemtn are oging to be 
in freq 2 and only one of htem is not giong to be but is freq 1 and they are sorted */


#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();
	if(n==1)return arr[0];
	if(arr[0]!=arr[1])return arr[0];
	if(arr[n-1]!=arr[n-2])return arr[n-1];

	int l = 1, h = n-1;
        while (l <= h) {
          int m = (l + h) / 2;
          if ((arr[m] != arr[m - 1]) && (arr[m] != arr[m + 1])){
			  return arr[m];
		  }
		  else{
			  if((m%2==0 && arr[m]==arr[m+1] )  || (m%2==1 && arr[m]==arr[m-1])){
				  l = m+1;
			  }
			  else{
				  h = m -1;
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