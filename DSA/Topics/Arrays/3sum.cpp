/*
currentlly the code below used hashing 

and is a better solution butn othe opti9mal 

*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> trip(int n,vector<int> &num){
    set<vector<int>> st;
    for(int i =0;i<n;i++){
        set<int> hashset;
        for(int j =0;j<n;j++){
            int third = -(num[i]+num[j]);
            if(hashset.find(third)!=hashset.end()){
                vector<int> temp = {third,num[i],num[j]};
                sort(temp.begin(),temp.end());
            }
            hashset.insert(num[j]);
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}



/*(

the below code is teh optimal solution for 8it 


this is the famous 3 pointer approch learn thyis is is very important 
)*/


#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> trip(int n ,vector<int> &nums){
    
    sort(nums.begin(),nums.end());  
    vector<vector<int>> ans;
    for(int i = 0;i<n;i++){
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum==0){
                vector<int> temp = {nums[i],nums[j],nums[k]};
                sort(temp.begin(),temp.end());
                ans.push_back(temp);
                j++;
                k--;

                while(j <k && nums[j]==nums[j-1])j++;
                while(j <k && nums[k]==nums[k+1])k--;
            }
            else if(sum<0){
                j++;
            }
            else{
                k--;
            }
        }
    }
    return ans;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}


