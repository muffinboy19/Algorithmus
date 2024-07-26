/*
this page would tell you about the first  and the last occurence of elemtns 
*/

#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &arr, int n ,  int k){
    int l = 0 , h = n-1,ans = n;
    while(l<=h){
        int m = (l+h)/2;
        if(arr[m]>=k){
            ans = m;
            h = m -1;
        }
        else{
            l = m+1;
        }
    }

    return ans;
}
int Upperbound(vector<int> &arr, int n , int k){
    int l = 0 , h = n-1 , ans = n;
    while(l<=h){
        int m = (l+h)/2;
        if(arr[m]>k){
            ans = m;
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    
    int lb = lowerBound(arr,n,k);
    if(arr[lb]!=k || lb==n){
        return {-1,-1};
    }
        return {lb,Upperbound(arr,n,k)-1};
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}





/*
The Below code would tell first and last occurance of the number using plain binary searchh
*/

#include<bits/stdc++.h>
using namespace std;
int firstOccurance(vector<int> &arr, int n,int k){
    int l =0 ,h = n-1,fr = -1;
    while(l<=h){
        int m = (l+h)/2;
        if(arr[m]==k){
            fr = m;
            h = m-1;
        }
        else if(arr[m]>k){
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    return fr;
}
int lastOccurance(vector<int> &arr,int n,int k){
    int l =0 ,h = n-1,lr = -1;
    while(l<=h){
        int m = (l+h)/2;
        if(arr[m]==k){
            lr = m;
            l = m+1;
        }
        else if(arr[m]>k){
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    return lr;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here


    int fr = firstOccurance(arr,n,k);
    if(fr==-1){return {-1,-1};}
    int lr = lastOccurance(arr,n,k);
    return {fr,lr};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}

/*
count  the  occurnce of an elmetn in a sorted array this woyld be done by simly subtarcing last occurancw - first occursand + 1 */