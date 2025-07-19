#include<bits/stdc++.h>
using namespace std;


bool isoperator(char x){
    switch(x){
        case '+': case '-' : case '/' : case '%' : case '^':
            return true;
    }
    return false;
}


string pretoinfix(string pre){
    stack<string>s;
    int l = pre.size();
    for(int i=l-1;i>=0;i--){
        if(isoperator(pre[i])){
            string op1=s.top();s.pop();
            string op2 = s.top();s.pop();
            string temp = "(" + op1 + pre[i] + op2 + ")";
            s.push(temp);
        }
        else{
            s.push(string(1,pre[i]));
        }

    }
    return s.top();
}

int main(){
    return 0;
}