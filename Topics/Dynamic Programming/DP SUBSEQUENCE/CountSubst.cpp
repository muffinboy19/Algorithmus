/*
i know htis quesiton has been done by us many time yet at the current stage i do not have enought clarity about 
why m i writing its algo again and again 
yet the imp thing e are missing here is that 


wehen the tarrget == 0 

    if(ind==0)
{
 ^ very very necessary for couting 

            if(target==0 && nums[0]==0) return 2;
            if(nums[0]==target || target==0) return 1;
            return 0;
}

this code shouold be used and why is this used will be future realised 

*/


// ^ under scrutiny 

\//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int ish(vector<vector<int>>&dp , int jj[],int n,int sum ,int i){
	    
	    if(i==0){
	        if(sum==0 && jj[0]==0){
	            // here 2 bcz one for target having 0 thus for watherver jj[o[ it would have BEE 
	            // true hence 1 for it 
	            // and the one for jj[0]==0 as it dserver its own case 
	            
	            return 2;
	            // ^ ask but why waas this necessary wont only target==0 count this case 
	        }
	        if(sum==0 || jj[0]==sum){
	            return 1;
	        }
	        return 0;
	        
	    }
	    /*
	    here we are not keeping hte tareget==0 criteia beca it fdoes not mean more 
	    0 can not come after it hence we wont inclue i9t 
	    */
	    
	    if(dp[i][sum]!=-1){
	        return dp[i][sum];
	    }
	    int pick = 0;
	    if(jj[i]<=sum){
	       pick = ish(dp,jj,n,sum-jj[i],i-1)%1000000007;   
	    }
	    int nopick = ish(dp,jj,n,sum,i-1)%1000000007;
	    return dp[i][sum]=(pick+nopick)%1000000007;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return ish(dp,arr,n,sum,n-1);
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

/*
Above is memoizaiton approch  also were u are fiding hger target==0 && i==0 is also called kanpscack aproch 
*/

// } Driver Code Ends


//^ belwo is the tabluation approcyh 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

    // Initialize the first row based on the first element of the array
        if (arr[0] <= sum) {
            dp[0][arr[0]] = 1;
    	}
    	if (arr[0] == 0) {
            dp[0][0] = 2;
        }
    	
    	
    	// ^ they are starting from 1 idk why have to find out ? 
    	for(int i=1;i<n;i++){
    	    for(int j=0;j<=sum;j++){
    	       int nopick = (dp[i-1][j])%(int)(1e9+7);
    	       int pick = 0;
    	       if(arr[i]<=j){
    	           pick = (dp[i-1][j-arr[i]])%(int)(1e9+7);
    	       }
    	    
    	       dp[i][j] = (pick+nopick)%(int)(1e9+7);
    	    }
    	}
    	return dp[n-1][sum];
    	
    	
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends