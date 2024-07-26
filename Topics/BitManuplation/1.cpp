#include<bits/stdc++.h>
using namespace std;
#define ll  long long int 
string inttobianary(int  n){
    string res="";
    while(n!=1){
        if(n%2==0)res+="1";
        else res+="0";

        n= n/2;
    }
    reverse(res.begin(),res.end());  

    return  res;

}

ll toDecimal(string s){
    ll powerof2 = 1;
    ll ans = 0 ;
    for (int i = s.size()-1; i>=0 ; i--)
    {
        if(s[i]=='1'){ans+= (1*(powerof2));}
        powerof2*=2;
    }
    return ans;
}

void swap2numbers(int a, int b){
    a = a^b;
    b = a^b;
    a = a^b;

    cout<<a<<" "<<b<<endl;

}
bool toset(int n,int i){
    if(n&(1<<i)!=0)return true;
    else return false;
}
int setThebit(int n,int i){
    return n|(1<<i);
}
int ClearTheBit(int n,int i){
    return n&~(1<<i);
}
int toogleTheBit(int n,int i){
    return n^(1<<i);
}
int RemoveTheRightSetMostBit(int n,int i){
    // here when we do n-1 we observe that the right most bit change to from 1 to 0 ( set bit )
    return (n&(n-1));
}
bool ToCheckIf2Power(int n,int i){
    // here when we do n-1 we observe that the right most bit change to from 1 to 0 ( set bit )
    if((n&(n-1))==0)return true;
    else return false;
}
int countTheNumberOfSetBit(int n){
    // not that tufght is couting hte rightmost set bits 
    int ct = 0 ;
    while(n!=0){
        n = n&(n-1);
        ct++;
    }

    return ct;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}