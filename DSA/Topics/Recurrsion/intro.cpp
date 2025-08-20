#include<bits/stdc++.h>
using namespace std;
int c =0;

void g(){
    cout<<"Gaurav"<<endl;
    c++;
    if(c==5){
        return;
    }
    g();
    
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    g();
    
    

    return 0;
}