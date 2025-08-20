#include<bits/stdc++.h>
using namespace std;

vector<int> pgefinder(vector<int> &arr){
    int n =arr.size();
    vector<int> pge(n,-1);
    stack<int> st;

    for(int i=0;i<n;i++){

        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(!st.empty())pge[i] = st.top();


        st.push(arr[i]);
    }
    return pge;
}



int main(){


}