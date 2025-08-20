/*
this one takcker hte same problem fo searching ina roated soted array but htis time ther wiill be 
dujplicates 
*/


#include<bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    // Write your code here.
     // Write your code here.
    // Return the position of K in ARR else return -1.
    int l = 0 , h = A.size()-1;
    while(l<=h){
        int m = (l+h)/2;
        if(A[m]==key){
            return true;
        }
        if(A[m]==A[l] && A[l]==A[h]){
            l++;h--;
        }

        if(A[l]<=A[m]){

            if(A[l]<=key && key<=A[m]){
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        else{
            if(A[m]<=key && key<=A[h]){
                l = m+1;
            }
            else{
                h = m-1;
            }

        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}