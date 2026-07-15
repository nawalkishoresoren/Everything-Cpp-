class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        vector<int>ans(nums.begin(),nums.end());
        for(auto num:nums)
        {
            ans.push_back(num);
        }
        return ans;      
    }
};