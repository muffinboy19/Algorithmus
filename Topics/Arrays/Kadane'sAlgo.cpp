/*
this algorithm is used to find  the maxium subarray sum from the array 
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0,maxSum = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxSum=max(sum,maxSum);
            if(sum<0){
                sum=0;
            }
         

        }
        return maxSum;
        
    }
};