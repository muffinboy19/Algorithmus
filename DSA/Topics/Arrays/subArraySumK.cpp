/*
this problem has negative numbers also hence we need some different algo for this 
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        map<int,int> mp;
        mp[0]=1;
        int ps = 0,cnt = 0;
        for(int i =0;i<nums.size();i++){
            ps+=nums[i];
            int rm = ps-k;
            cnt+=mp[rm];
            mp[ps]+=1;
        }

        return cnt;
        
    }
};