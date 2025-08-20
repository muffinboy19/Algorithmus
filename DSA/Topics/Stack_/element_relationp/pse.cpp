#include<bits/stdc++.h>
using namespace std;


vector<int> psefinder(vector<int> &arr){
    int n = arr.size();
    stack<int> st;

    vector<int> pse(n,-1);

    for(int i=0;i<n;i++){

        while(!st.empty() && st.top() >= arr[i]){
            st.pop();// so now we vae the smalled elmetn then 
            // our arr[i];
        }
        if(!st.empty())pse[i] = st.top();


        st.push(arr[i]);
    }
}