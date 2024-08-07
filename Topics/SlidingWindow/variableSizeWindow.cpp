/*
This question we will study how to shrunk the windws and expand it expertly 
*/

/*
The modthod of wiggling the size of hte windows i call it wiggling is like a worm movfement first 
go till u satify the condition and then take ur starting point and go back to the starting point 
wit hit this way the legnth is now reudced this wriggling motion is what is 
^ variable size windows 

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m,n;
        for(auto it:t)m[it]++;
        int l =0,r=0,have = 0,required = t.size();
        int minLenght = INT_MAX;
        string nan="";
        int minStart =0;
        while(r<s.size()){
           if(m[s[r]]>0)required--; 
           m[s[r]]--;
           r++;

           while(required == 0){
            if(r-l < minLenght){
                minStart =l;
                minLenght = r-l; 
            }
            m[s[l]]++;
            if(m[s[l]]>0)required++;
            l++;
           }          
        }
        if(minLenght !=INT_MAX){
            return s.substr(minStart,minLenght);
        }
        return "";
        
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}