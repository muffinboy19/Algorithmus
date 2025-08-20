/*
this code is also using backtracking so This algo should be learnt by hard

^IMPORTANT 

STEPS : for it 

first maintain an temp string 
here you have 2 options either to take the index or not to take the index 

this code works of strings 

*/

#include<bits/stdc++.h>
using namespace std;
void solve(int i, string s, string &f) {
	if (i == s.length()) {
		cout << f << " ";
		return;
	}
	//picking 
	f = f + s[i];
	solve(i + 1, s,  f);
	//poping out while backtracking
	f.pop_back();
	solve(i + 1, s,  f);
}
int main() {
	string s = "abc";
	string f = "";
	cout<<"All possible subsequences are: "<<endl;
	solve(0, s, f);
}

/*
^ This new code works for arrays/vectors format 

This code uses bitManuplaiton to print the powerset

*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> powerSet(vector<int>&nums)
{
    vector<vector<int>> sets;
    int n = nums.size();
    int subsetsCount = 1 << n; //  this is equal 2 ^ n ;
    for(int  i = 0;i<subsetsCount;++i){
        vector<int> subSet;
        for(int j = 0;j<n;++j){
            if(i&(1<<j)){
                subSet.push_back(nums[j]);
            }
        }
        sets.push_back(subset);
    }
    return sets;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}   