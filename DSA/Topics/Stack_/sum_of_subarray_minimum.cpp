#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int sumSubarrayMins(vector<int>& a) {
    stack<pair<int, int>> stp, stn;
    vector<int> left(a.size()), right(a.size());
		
    for(int i = 0; i < a.size(); i++) left[i] =  i + 1;
    for(int i = 0; i < a.size(); i++) right[i] = a.size() - i;
		
    for(int i = 0; i < a.size(); i++){
      while(!stp.empty() && stp.top().first > a[i]) stp.pop();
      left[i] = stp.empty()? i + 1: i - stp.top().second;
      stp.push({a[i],i});
			
      while(!stn.empty() && stn.top().first > a[i]){
        auto x = stn.top();stn.pop();
        right[x.second] = i - x.second;
      }
      stn.push({a[i], i});
    }

    int ans = 0, mod = 1e9 +7;
    for(int i = 0; i < a.size(); i++){
      ans = (ans + a[i]*left[i]*right[i])%mod;
    }
    return ans;
  }
};

int main(){


}