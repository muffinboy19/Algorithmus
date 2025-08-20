/*
this code is goin gto find the square root of the nubmer using the binna4ey stach 
als ofom now on the quetion which are gooing to com are of the type range based binary search 

*/



#include<bits/stdc++.h>
using namespace std;
int floorSqrt(int n)
{
    long long int  l = 1,h = n;
    while(l<=h){
        long long int  m= (l+h)/2;
        long long int val = m*m;
        if(val<=n){
            l = m+1;
        }
        else{
            h = m-1;
        }
    }
    return h;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    

    return 0;
}