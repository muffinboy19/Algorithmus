/*
This type of code we are going to sovle teh following methods
^ count paths 
^ count paths with obstacles on them
^ minimum path sum 
^ max path sum 
^ Triangle proble
^ 2 start points
*/


// & This is the dp-8 ( Total unique paths)
// * RECURSION SOULUTION 
/*
step 1 : determine a base case so that you would return 1 
(as this is a counting question we would need that )

step 2: return 0 on the path that you do not wish to count 
step 3:  now do all the stuff (which means here sum all the pathways)
*/
/*
you can only apply / convert a reccrusion soilution to a dp solution only if there is 
overlappign cases else you


try to imagine the recurssion tree whil righti therecursiosn code 

*/
// * MEMOISZATION OR NOT 


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int l=0,t=0;
                if(i==0 && j==0){dp[i][j]=1;continue;}
                if(i>0) l=dp[i-1][j] ;
                if(j>0) t=dp[i][j-1];
                dp[i][j]=l+t;
            }
        }

        return dp[m-1][n-1];
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}
