// User function Template for C++

class Solution {
  public:
  
    bool isoperator(char c){
        switch(c){
            case '+':case '-':case '*':case '^':case '%':case '/':
                return true;
        }
        return false;
    }
    string preToPost(string pre_exp) {
        
        stack<string>st;
        int l = pre_exp.size();
        for(int i=l-1;i>=0;i--){
            
            if(isoperator(pre_exp[i])){
                
                
                string op1 = st.top();st.pop();
                string op2 = st.top();st.pop();
                string temp = op1 + op2 + pre_exp[i];
                st.push(temp);
            }
            else {
                st.push(string(1,pre_exp[i]));
            }
        }
        return st.top();
    }
};