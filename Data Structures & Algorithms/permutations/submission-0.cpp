class Solution {
    vector<vector<int>> ans;

    void solve(int index,vector<int>& nums,vector<int>&temp)
    {
        if(index>=nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<nums.size();++i)
        {
            swap(nums[i],nums[index]);
            temp.push_back(nums[index]);
            solve(index+1,nums,temp);
            temp.pop_back();
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        solve(0,nums,temp);
        return ans;
    }
};
