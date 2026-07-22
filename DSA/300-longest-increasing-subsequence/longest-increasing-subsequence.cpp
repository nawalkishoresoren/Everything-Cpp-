class Solution {
public:
    int solve(vector<int>& nums,int i, int p, vector<vector<int>>&dp)
    {
        if(i>=nums.size())
            return 0;
        
        if(p!=-1 and dp[i][p] != -1)
            return dp[i][p];
        int take = 0;

        if(p == -1 or nums[i] > nums[p])
        {
            take = 1 + solve(nums,i+1,i,dp);
        }
            
        int skip = solve(nums,i+1,p,dp);

        if(p!=-1)
            return dp[i][p]=max(skip,take);
        return max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,0,-1,dp);
    }
};