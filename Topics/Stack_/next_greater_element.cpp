#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        

        int n = nums1.size();
        vector<int> nge(n,-1); // this wil lstoer het next greater elment o hte aray 
        stack<int> st;


        /// ookay so this code is ont o(n) 
          // we are going to travers the aray tiwcie 


          for(int i= 2*n -1 ;i >=0 ;i--){
            // from the back 

            while (!st.empty() && st.top() <= nums1[i%n]){
                st.pop();
            }
            // so now wah we got ishte nge 

            if(i<n){
                if(!st.empty())nge[i] = st.top();
            }

            st.push(nums1[i%n]);
          }

        return nge;
    }
};