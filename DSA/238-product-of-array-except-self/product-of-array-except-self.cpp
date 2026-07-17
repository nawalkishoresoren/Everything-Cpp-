class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int>prefix_mul(nums.size(),1);
        vector<int>suffix_mul(nums.size(),1);
        vector<int>ans(nums.size(),1);

        for(int i=1;i<nums.size();i++)
        {
            prefix_mul[i] = prefix_mul[i-1] * nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            suffix_mul[i] = suffix_mul[i+1] * nums[i+1];
        }
        for(int i=0;i<nums.size();i++)
        {
            ans[i] = prefix_mul[i] * suffix_mul[i];
        }
        return ans;
    }
};