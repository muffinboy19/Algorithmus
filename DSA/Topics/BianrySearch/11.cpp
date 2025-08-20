/*
find the nth rooth fo ht number  m */ 

#include<bits/stdc++.h>
using namespace std;
/*
return 1 if == m
return 2 if > m
return 0 <  m
*/

int func(int mid,int n,int m){
  long long ans = 1;
  for(int i = 0 ;i<n;i++){
    ans = ans*mid; 
    if(ans>m)return 2;
  }

  if(ans == m)return 1;
  return 0 ;
}

int NthRoot(int n,int m){
  int low = 1,high = m;
  while(low<=high){
    int mid = (low+high)/2;
    int midN = func(mid,n,m);
    if(midN== 1){
      return mid;
    }
    else if(midN==0)low = mid+1;
    else high = mid-1;
  }
  return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}