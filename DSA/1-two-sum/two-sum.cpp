class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int>umap;

        for(int i=0;i<nums.size();i++)
        {
            int new_target = target - nums[i];
            if(umap.find(new_target) == umap.end())
            {
                umap[nums[i]] = i;
            }
            else
            {
                return {umap[new_target],i};
            }
        }
        return {-1,-1};
    }
};