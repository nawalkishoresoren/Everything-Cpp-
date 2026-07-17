class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int,int>umap;
        for(auto num:nums)
        {
            umap[num]++;
        }
        int max_count = 0;
        for(auto num:umap)
        {
            if(umap.find(num.first-1) == umap.end())
            {
                int count = 1;
                auto temp = num.first;
                while(umap.find(temp+1) != umap.end())
                {
                    temp = temp+1;
                    count++;
                }
                max_count = max(max_count,count);
            }
            
        }
        return max_count;
    }
};