#include<bits/stdc++.h>
using namespace std;
vector<int> nsefinder(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> nse(n,-1);

    for(int i=0;i<n;i++){

        while(!st.empty() && arr[i] < arr[st.top()]){
            nse[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return nse;
}
int main(){


}