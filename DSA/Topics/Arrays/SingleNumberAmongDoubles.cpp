class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ish = nums[0];
        for(int i =1;i<nums.size();i++){
            ish^=nums[i];
        }
        return ish;
        
    }
};