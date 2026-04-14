class Solution {
    int solve(vector<int>& cost,int idx,vector<int>&dp)
    {
        if(idx<0)return 0;
        else if(idx==0)return cost[0];

        else if(dp[idx]!=-1)return dp[idx];

        return dp[idx]=cost[idx] + min(solve(cost,idx-1,dp),solve(cost,idx-2,dp)); 
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);

        vector<int> dp(cost.size(),-1);

        return solve(cost,(int)cost.size()-1,dp);
    }
};
