/*

the ship capcity question is almost a standar binary quetsioni 
*/ 


#include<bits/stdc++.h>
using namespace std;
int func(vector<int> &a,int mid){
    int days= 1;
    int load = 0;
    for(auto it:a){
        if(load+it > mid){
            days++;
            load = it;
        }
        else{
            load +=it;
        }
    }

    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    // now i understand the min l has to be == max elmetn as oherwise you wont be aable to ship on that day and that is wrong 
    // here what i feel  is that the max elmetns is still not ennough to do that task of sthiping so ehter is not diffrencd 
    /*
    betwen the number  1 and the max elmetn accordin to me some how the max elmetn is more thabtn that 
    so to make sure i dont miss any test case i will be using the min as 1 

    and yes the max would be the sum of all elmetns .. 


    */
    
    int l = *max_element(weights.begin(),weights.end()),h = accumulate(weights.begin(),weights.end(),0);
    while(l<=h){
        int m = (l+h)/2;
        int days_m = func(weights,m);
        if(days_m<=d){
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    return l;

    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}