/*
a painters problem 
*/

#include<bits/stdc++.h>
using namespace std;
int func(vector<int> &a,int mid){
    int painter = 1;
    int currTime = 0 ;
    for(int i = 0 ;i<a.size();i++){
        if(a[i] + currTime <= mid){
            currTime +=a[i];
        }
        else{
            painter++;
            currTime = a[i];
        }
    }
    return  painter;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.

    /* 
    here the l  would be the min of the max possbile vale of the arrau and the h would be the sum 
    */ 
    int l = *max_element(boards.begin(),boards.end());
    int h= accumulate(boards.begin(),boards.end(),0);

    while(l<=h){
        int mid = (l+h)/2;
        int alpah = func(boards,mid); // this repsresets the numbre of lefnot one painter shold paint 
        if(alpah <= k){
            h = mid-1;
        }   
        else{
            l = mid +1;
        }
    }
    return l;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}