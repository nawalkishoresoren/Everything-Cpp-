class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        unordered_map<int,int>umap;
        umap[0]++; 
        int sum = 0, count = 0, remainder = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            remainder = sum % k;
            if(remainder<0)
                remainder += k;
            
            count += umap[remainder];
            umap[remainder]++;
        }
        return count;
    }
};