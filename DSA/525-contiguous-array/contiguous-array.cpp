class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int,int>umap;
        int sum = 0, max_arr = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                sum += 1;
                if(sum==0)
                    max_arr = max(max_arr,i+1);

            }
            else
            {
                sum -= 1;
                if(sum==0)
                    max_arr = max(max_arr,i+1);
            }

            if(umap.find(sum) == umap.end())
            {
                umap[sum] = i;
            }
            else
            {
                max_arr = max(max_arr,i - umap[sum]);
            }
        }
        return max_arr;

    }
};