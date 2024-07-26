/*
this code is of to print all the subsequnce 
done using the method of picORnopic
*/

#include<bits/stdc++.h>
using namespace std;
void prints(int i,vector<int> &ds,int csum,int sum,int arr[],int n){
    if(i==n){
        if(csum==sum){
            for(auto it:ds)cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[i]);
    csum+=arr[i];
    prints(i+1,ds,csum,sum,arr,n);
    ds.pop_back();
    csum-=arr[i];
    prints(i+1,ds,csum,sum,arr,n);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[] = {1,2,1};
    int n =3;
    int sum=2;
    vector<int> ds;
    prints(0,ds,0,sum,arr,n);
    

    return 0;
}

/*
modifying the below code to print only one subsequece 
*/

#include<bits/stdc++.h>
using namespace std;
bool prints(int i,vector<int> &ds,int csum,int sum,int arr[],int n){
    if(i==n){
        if(csum==sum){
            for(auto it:ds)cout<<it<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }
    ds.push_back(arr[i]);
    csum+=arr[i];
    if(prints(i+1,ds,csum,sum,arr,n)==true)return true;
    ds.pop_back();
    csum-=arr[i];
    if(prints(i+1,ds,csum,sum,arr,n)==true)return true;


    return false;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[] = {1,2,1};
    int n =3;
    int sum=2;
    vector<int> ds;
    prints(0,ds,0,sum,arr,n);
    

    return 0;
}