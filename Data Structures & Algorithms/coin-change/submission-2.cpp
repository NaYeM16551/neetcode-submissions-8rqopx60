class Solution {
    int solve(int idx,vector<int>& coins, int amount,vector<vector<int>>&dp)
    {
        if(amount==0)return 0;
        else if(idx>=coins.size())return 1e9;

        if(dp[idx][amount]!=-1)return dp[idx][amount];

        int include = 1e9;

        if(coins[idx]<=amount)
        {
            include = 1 + solve(idx,coins,amount-coins[idx],dp);
        }

        int exclude = solve(idx+1,coins,amount,dp);
               
        return dp[idx][amount] = min(include,exclude);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
       
       int n = coins.size();

       vector<vector<int>> dp(n,vector<int>(amount+1,-1));

       int res = solve(0,coins,amount,dp);
       return res >= 1e9 ? -1 : res;
        
    }
};
