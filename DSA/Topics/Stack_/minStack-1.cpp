#include<bits/stdc++.h>

using namespace std;


class minStack{
    stack<pair<int,int>> st;



public:
    void push(int x){

        int min;

        if(st.empty()){
            min = x;
        }
        else {
            min = std::min(st.top().second,x);
        }
        // soo curent the push pattenr is that the first 
        // i the emetn and the scond ithe miinum lemtne till that layer so wwe can esaily ge 
        // the min value till the tireaiton .
        st.push({x,min});
    }

    void pop(){
        st.pop();
    }
    int peek(){
        return st.top().first;
    }

    int getMin(){
        return st.top().second;
    }


};