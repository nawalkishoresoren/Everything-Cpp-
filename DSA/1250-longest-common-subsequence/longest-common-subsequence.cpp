class Solution {
public:
    int dp[1001][1001];
    int solve(int i, string &s1, int j, string &s2)
    {
        if(i>=s1.size() || j>=s2.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
        {
            return dp[i][j] = 1 + solve(i+1,s1,j+1,s2);
        }
        return dp[i][j] = max(solve(i+1,s1,j,s2),solve(i,s1,j+1,s2));
    }

    int longestCommonSubsequence(string text1, string text2) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(0,text1,0,text2);
    }
};