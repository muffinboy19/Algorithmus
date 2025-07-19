/// postfix is called 
// the revrese plish notaion 

// rpn

// a+ b = AB+
// a + b*c = abc*+


#include<bits/stdc++.h>
using namespace std;

int prec(char c){
     // this is nothing it  jsut  gives the precdene of hte 
    // of the oprator that is going to be used here.

    if(c=='^')return 3;
    if(c=='*' || c=='/')return 2;
    if(c=='+' || c=='-')return 1;
    return -1;
}


string infixtopostfix(string s){
    stack<char> st;
    string res;

    for(int i=0;i<s.size();i++){
        char c = s[i];
        // when it is a opreantd 

        if(isalnum(c)){
            res+=c;
        }
        else if(c=='(')st.push(c);
        else if(c==')'){
            while (!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty())st.pop();
        }
        else{
            while(!st.empty() && prec(st.top())>=prec(c)){
                if(c=='^' && st.top()=='^')break;

                res+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }



    while(!st.empty()){
        res+=st.top();
        st.pop();
    }

    return res;

}