/*
there is exits a inbuilt stl function which does that 
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a = "gaurav";

    cout<<next_permutation(a.begin(),a.end())<<endl;
    cout<<a<<endl;
    

    return 0;
}



/*
there exits another solution whichc does not taek help of stl functions
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_set<int> s;
        for(auto it:nums){
            s.insert(it);
        }

        for(auto it:s){
            if(s.find(it-1)==s.end()){
                int cnt = 1;
                int x =1;
                while(s.find(it+x)!=s.end()){
                    x++;
                    cnt++;
                }

                ans=max(cnt,ans);
            }
        }

        return ans;
        
    }
};