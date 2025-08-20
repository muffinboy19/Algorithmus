#include<bits/stdc++.h>
using namespace std;

vector<int> ngefinder(vector<int> &arr){

  int n = arr.size();

  vector<int> nge(n,-1); 
  stack<int> st; // the stack is for  index

  for(int i=0;i<n;i++){
    while(!st.empty() && arr[i] > arr[st.top()]){
      nge[st.top()] = arr[i];
      st.pop();
    }
    st.push(i);
  }
  return nge;
}

int main(){


}