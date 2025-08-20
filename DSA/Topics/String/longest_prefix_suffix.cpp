#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        
        // so we are going to implemetn the kmp algorhtim 

        // the first part of this allgorhitm is called as 
        // longest prefix suffix portion.
        // (LPS)

        // soo we will create 
        // actaullyi was confuseed as i htogh the whie comare 
        // for the suffix n prefix it was comparing somem other 
        // string it will calcualte that on the sma string itslef


        /// emmple AAAA 
        /// here we can easily see that teh this is lps is 
        // 0 1 2 3 as the last 3 is same as the first 3 hence the 3 
        if(needle=="")return 0;

        vector<int> lps(needle.size(),0);

        int prevlps=0,i=1;

        while(i<needle.size()){
            // smly checingtaht hte current is matching the previssou lps 

            if(needle[i] == needle[prevlps]){
                lps[i] = prevlps+1;
                prevlps++;
                i++;
            }
            else if(prevlps==0){
                    lps[i] =0;
                    i++;
            }
            else{
                prevlps= lps[prevlps-1];
            }
        }


        i=0;
        int j=0;

        while(i < haystack.size()){

            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            else{
                if(j==0){
                    i++;
                }
                else{
                    j = lps[j-1];

                }
            }
            if(j==needle.size()){
                return i - needle.size();
            }
        }
        return -1;









    }
};
int main(){
    return 0;
}