#include<bits/stdc++.h>
using namespace std;
bool isop(char c){
    if( ('a' <= c && c<='z' ) || ('A' <=c && c<= 'Z')){
        return true;
    }
    return false;
}

string func(string exp){
    stack<string>s;
    for(int i=0;exp[i]!='\0';i++){
        if(isop(exp[i])){
            string op(1,exp[i]);
            s.push(op);
        }
        else{
            string op1 = s.top();s.pop();
            string op2 = s.top();s.pop();
            s.push("("+op2 + exp[i] + op1 + ")");
        }
    }

    return s.top();
}
int main(){
    return 0;
}