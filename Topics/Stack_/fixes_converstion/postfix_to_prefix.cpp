// User function Template for C++

class Solution {
  public:
  
    bool isop(char c){
        switch(c){
            case '+':case '-':case '*':case '/':case '^':case '%':
                return true;
        }
        return false;
    }
    string postToPre(string post_exp) {
        // Write your code here
        stack<string>st;
        for(int i=0;i<post_exp.size();i++){
            if(isop(post_exp[i])){
                string op1 = st.top();st.pop();
                string op2 = st.top();st.pop();
                st.push(post_exp[i] + op2+op1);
            }
            else st.push(string(1,post_exp[i]));
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};