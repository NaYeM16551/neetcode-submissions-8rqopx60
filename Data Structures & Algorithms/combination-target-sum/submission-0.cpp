class Solution {
    vector<vector<int>> ans;

    void solve(int i,vector<int>& nums,int target,int sum,vector<int>&temp)
    {
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        if(sum>target)
          return;
        if(i==nums.size())
        {
            if(sum==target)
            {
                ans.push_back(temp);
                return;

            }
            else
             return;
        }

        temp.push_back(nums[i]);
        solve(i,nums,target,sum+nums[i],temp);
        temp.pop_back();
        solve(i+1,nums,target,sum,temp);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        solve(0,nums,target,0,temp);
        return ans;
    }
};
