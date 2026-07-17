class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>umap;
        umap[0] = 1;

        int prefix_sum = 0;
        int count = 0;

        for(auto num:nums)
        {
            prefix_sum+=num;

            if(umap.find(prefix_sum-k) != umap.end())
            {
                count += umap[prefix_sum-k];
            }
            umap[prefix_sum]++;
        }
        return count;
    }
};