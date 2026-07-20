class Solution {
public:
    int solve(int idx, vector<int>& coins, int amount,vector<vector<int>>&dp)
    {
        if(amount == 0)
            return 0;
        
        if(amount<0 || idx<0)
            return 1e9;

        int take = 1e9;

        if(dp[idx][amount]!= -1)
            return dp[idx][amount];

        if(coins[idx]<=amount)
        {
            take = 1 + solve(idx,coins,amount - coins[idx],dp);
        }
        int skip = solve(idx-1,coins,amount,dp);
        
        return dp[idx][amount] = min(take,skip);

    }
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1, -1));
        int ans =  solve(coins.size()-1,coins,amount,dp);
        return ans==1e9?-1:ans;
    }
};