class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int>ans(nums.size(),1);
        int suffix_mul =1;

        for(int i=1;i<nums.size();i++)
        {
            ans[i] = ans[i-1] * nums[i-1];
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i] = suffix_mul * ans[i];
            suffix_mul = suffix_mul * nums[i];
        }
        return ans;
    }
};