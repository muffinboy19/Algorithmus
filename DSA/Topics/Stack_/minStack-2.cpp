// htis method is muchc beter 
// bcz we here use a encoidng to tore the min  value 
// witout taking the exyra sapce for it .



#include<bits/stdc++.h>
using namespace std;


class minStack{
    stack<long long> st;
    long long mini;


    minStack(){
        while(!st.empty())st.pop();
        mini = INT_MAX; // this above line empties the stack 
        // for the use .
    }


    void push(int x){
        long long val = x;
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            // but if the stack is not empty 

            if(val < mini){
                st.push(2*val- mini);
                mini = val;
            }
            else{
                st.push(val);
            }
        }
    }

    void pop(){
        if(st.empty())return;

        long long el = st.top();

        st.pop();
        // her ehte st.top9 is acuatl 2*(val) - mini;
        if(el<mini){
            // so if it is greate than mini the tne vacctuail vaule is 
            // is alos greate than ini ofc 
            mini = 2* mini - el;
        }
    }

    int top(){
        if(st.empty())return -1;

        long long el = st.top();
        if(el<mini)return mini;
        return el;
    }

    int getMin(){
        return mini;
    }



};


