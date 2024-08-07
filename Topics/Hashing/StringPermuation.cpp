/*
This question we have to tell wether the string 1 is presint in any but permuation for in string 2 
and we wilil do this question using hasharray
*/

/*
The majority difference here is that  here hashMap comparision is possible as the
count of the hasharray is only 26
^ hash comparissoin possiblie when the size is 26 only 
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checker(vector<char> v1,vector<char>v2){
        for(int i =0;i<26;i++){
            if(v1[i]!=v2[i])return false;
        }/*
        This code is the game changer as it checks the hash arar6s */
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<char> ish(26,0),osh(26,0);
        for(auto it:s1){
            ish[it-'a']++;
        }
        int l =0,r=s1.size();
        while(l<r){
                osh[s2[l]-'a']++;
                l++;
        }
        l=0;
        while(r<s2.size()){
            if(true==checker(ish,osh))return true;
            osh[s2[l]-'a']--;
            osh[s2[r]-'a']++;
            l++;r++; 
        }
        if(true==checker(ish,osh))return true;
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}