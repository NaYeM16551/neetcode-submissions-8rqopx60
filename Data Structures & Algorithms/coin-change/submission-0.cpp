class Solution {
    int solve(int idx,vector<int>& coins, int amount,vector<vector<int>>&dp)
    {
        if(amount==0)return 0;
        else if(idx>=coins.size())return -100;

        if(dp[idx][amount]!=-1)return dp[idx][amount];

        int include = -4;

        if(coins[idx]<=amount)
        {
            include = 1 + solve(idx,coins,amount-coins[idx],dp);

        }

        int exclude = solve(idx+1,coins,amount,dp);

        int ans = 0;

        if(include*exclude<0)
           return dp[idx][amount] = max(include,exclude);
               

        return dp[idx][amount] = min(include,exclude);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
       
       int n = coins.size();

       vector<vector<int>> dp(n,vector<int>(amount+1,-1));

       return max(-1,solve(0,coins,amount,dp));
        
    }
};
