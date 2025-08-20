class Solution {
public:

    int inversiton(vector<int>& a){
        int osh = 0;
        for(int i=0;i<a.size()-1;i++)
        {

            if(a[i]>a[i+1])osh++;
        }

        return osh;
    }
    bool check(vector<int>& nums) {
        int ish = inversiton(nums);
        if(ish==0)return true;
        if(ish==1 && nums[0]>=nums[nums.size()-1])return true;
        return false;
    }
};


/*


why did i feel this was worth noting down as we have to know that how to check if a array is roated or not in array 

*/