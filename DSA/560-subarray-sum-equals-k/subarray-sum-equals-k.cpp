class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>umap;
        umap[0]++;

        int prefix_sum = 0, result = 0;

        for(int i = 0; i<nums.size(); i++)
        {
            prefix_sum += nums[i];
            
            
            result += umap[prefix_sum - k];
            umap[prefix_sum]++;
            
        }
        return result;
    }
};