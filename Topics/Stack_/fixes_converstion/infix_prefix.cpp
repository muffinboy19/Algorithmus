#include<bits/stdc++.h>
using namespace std;

bool isop(char c){

    return (!isalpha(c)&& !isdigit(c));
    // will only allow those if the c is not alhpa n and a digit
}


int perc(char c){

    if(c=='^')return 3;
    else if(c=='*' || c=='/')return 2;
    else if(c=='+'||c=='-')return 1;
    return -1;
}

string func(string inf){
    

    inf = "(" + inf + ")";
    int l = inf.size();
    stack<char>st;

    string res="";

    for(int i=0;i<l;i++){
        if(isalpha(inf[i]) || isdigit(inf[i])){
            res+=inf[i];
        }
        else if(inf[i] == '('){
            st.push('(');
        }
        else if(inf[i] == ')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();

            }
            st.pop();
        }

        else{

            if(isop(st.top())){
                if(inf[i]=='^'){
                    while(perc(inf[i]) <= perc(top())){
                        res+=st.top();
                        st.pop();
                    }


                }
                else {
                    while(perc(inf[i])< perc(st.top())){
                        res+=st.top();
                        st.pop();
                    }
                }

                st.push(inf[i]);
            }
        }


    }

    while(!st.empty()){
        res+=st.top();st.pop();
    }
    return res;
}