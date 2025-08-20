 #include<bits/stdc++.h>
 using namespace std;
 int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     

    int n,k;cin>>k;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int l = 0 , h = n-1;
    while(l<=h){
        int m = (l+h)/2;
        if(a[m]==k){cout<<m<<endl;}
        else if(a[m]>k){h = m-1;}
        else{l=m+1;}
    }
    cout<<-1<<endl;
    
 
     return 0;
 }


 /// now the recurse implemnation of hte binary Search 

 #include<bits/stdc++.h>
 using namespace std;

 

int myfun(vector<int> & a, int l , int h , int t){

    if(l>h){
        return -1;
    }
    int m = (l+h)/2;
    if(a[m]==t)return m;
    else if(a[m]> t){
       return myfun(a,l,m-1,t);
    }
    else{
         return myfun(a,m+1,h,t);
    }
}

int search(vector<int> &nums, int target) {

    int l = 0 , h = nums.size()-1;
    return myfun(nums,l,h,target);
    
}

 int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);

    
     
 
     return 0;
 }