
#include<bits/stdc++.h>
using namespace std;
int prints(int i,int csum,int sum,int arr[],int n){
    if(i==n){
        if(csum==sum){
            // for(auto it:ds)cout<<it<<" ";
            // cout<<endl;
            return 1;
        }
        return 0;
    }
    csum+=arr[i];
    int l = prints(i+1,csum,sum,arr,n);
    csum-=arr[i];
    int r = prints(i+1,csum,sum,arr,n);


    return l+r;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[] = {1,2,1};
    int n =3;
    int sum=2;
    cout<<prints(0,0,sum,arr,n)<<endl;
    

    return 0;
}