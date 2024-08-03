/*

* brain steps for this problem: 

steps 1 : first check if the stack is empty or not 
step 2 : then sperate the top from the stack and sort the remaing stack 
step 3 : this stepp will go till we get an empty stack throug hhrecursion only
step 4: when  you remove the top elemtn store it in int x 
step 5 : then at last create anothyer fuciont sortInsert
this funciotn will also strp out the elemntrs one by one till the stack gets empty or it is greater than stack.top() 
if true then s.push() directly 
*/

#include<bits/stdc++.h>
using namespace std;
void insertStack(stack<int> &s , int x){
    if(s.empty()|| x>s.top()){
        s.push(x);
        return ;
    }
    int temp =  s.top();
    s.pop();
    insertStack(s,x);

    s.push(temp);

}
void sortStack(stack<int> &s){
    if(!s.empty()){
        int x = s.top();
        s.pop();
        sortStack(s);
        insertStack(s,x);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}