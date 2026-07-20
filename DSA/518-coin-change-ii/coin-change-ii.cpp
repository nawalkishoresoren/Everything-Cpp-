class Solution {
public:
    int solve(int idx, vector<int>& coins, int amount, vector<vector<int>>&dp)
    {
        if(amount == 0)
            return 1;
        
        if(idx==coins.size())
            return 0;
        
        if(dp[idx][amount]!=-1)
            return dp[idx][amount];

        if(coins[idx]>amount)
        {
            return dp[idx][amount] = solve(idx+1,coins,amount,dp);
        }
        int take = solve(idx,coins,amount - coins[idx],dp);
        int skip = solve(idx+1,coins,amount,dp);

        return dp[idx][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>>dp(coins.size(),vector<int>(amount + 1,-1));
        return solve(0,coins,amount,dp);
        
    }
};