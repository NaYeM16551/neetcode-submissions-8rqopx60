class Solution {
    vector<vector<int>> ans;


    void solve(vector<int>& candidates, int target,int i,vector<int>&temp)
    {
        if(target==0 and find(ans.begin(),ans.end(),temp)==ans.end())
        {
            ans.push_back(temp);
            return;
        }

        if(i>=candidates.size() or target<0)
          return;

        //taking elem at index i
        temp.push_back(candidates[i]);
        solve(candidates,target-candidates[i],i+1,temp);
        temp.pop_back();

        //not taking elem at index i
        solve(candidates,target,i+1,temp);  


    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;

        solve(candidates,target,0,temp);
        return ans;
    }
};
