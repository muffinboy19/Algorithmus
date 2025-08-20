#include<bits/stdc++.h>
using namespace std;
/*
Can be easily stored in array as the segment ree is already indnexed 
the index of the child of hte parnet with the idnxx i is 
2* i +  1 and 2 * i + 2 

bascially it used to store max values n min values of  a range 
after u wite the range 
teh 0 nodes is for ( 0 - N )
then 1 node is for ( 0 - n/2 ) and 2 node is for ( n/2 - n )
in this way all the leaf nodes are elements of 

for a segmeent tree 4*N space has to be allocated 
*/


/*
time to build 0(N) == (2*N + 2)
time to query 0(logN)
HOW TO QUERY FOR A RNAGE 
1. completly lies in a range  of our question ( then return the value )
2. it does not lie in the range (return some INT_MIN or garble value which would be ignored )
3. it overlaps some ranges  ( go bot the direction) 
*/

int a[100005],seg[4*(100005)];
void build(int ind,int low,int high){

    if(low==high){
        seg[ind] = a[low];
        return;
    }
    int mid = (low + high)/2;
    build(2*ind +1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);

}

int query(int ind,int low,int high,int l ,int r){

    if( low >= l && high<=r){
        return seg[ind];
    }
    if(high < l || low > r){
        return INT_MIN;
    }
    int mid = (low+high)/2;
    int left = query(2*ind + 1,low,mid,l,r);
    int right = query(2*ind + 2 , mid +1,high,l,r);

    return max(left,right);

}
int main(){

    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    build(0,0,n-1);

    int q;
    cin>>q;
    while(q--){

        int l,r;
        cin>>l>>r;

        cout<<query(0,0,n-1,l,r)<<endl;


    }
}



