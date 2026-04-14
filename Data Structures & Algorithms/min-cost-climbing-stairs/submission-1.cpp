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

        int prev1 = cost[1],prev2=cost[0];

        int ans = min(prev1,prev2);

        for(int i=2;i<cost.size();++i)
        {
            ans = cost[i] + min(prev1,prev2);

            prev2=prev1;
            prev1=ans;
        }

        return ans;
    }
};
