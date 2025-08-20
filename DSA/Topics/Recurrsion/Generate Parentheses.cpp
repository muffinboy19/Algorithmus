/*
& BACKTRACKING 

! here first time the conept of backtracking is going to be used 


steps: 

1. we have to navigate using the number of clsoe nad nuymber of open and close 
if( open< num){ 
open can be added 

also make sure to back track here as thgis is a possiblity not hte coirrect ansnwere here 


2 . if ( close < open) { 

close can be added 
also make sure to add thhe neccsarry backtracking  code for it 
}
*/


class Solution {
public:
    void ff(string p,int num , int open , int close,vector<string>&ish){
        if(open == close  && close == num){
            ish.push_back(p);
            return;
        }
        if(open<num){
            p+="(";
            open++;
            ff(p,num,open,close,ish);
            open--;
            p.pop_back();
        }
        if(close<open){
            p+=")";
            close++;
            ff(p,num,open,close,ish);
            p.pop_back();
            close--;
        }
        return;

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ish;
        ff("",n,0,0,ish);
        return ish;
    }
};