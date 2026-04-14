class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();

        set<vector<int>> ans;

        for(int mask=0;mask<(1<<n);++mask)
        {
            vector<int> temp;
            for(int j=0;j<n;++j)
            {
                if(mask & (1<<j))
                {
                    temp.push_back(nums[j]);
                }
            }
            sort(temp.begin(),temp.end());
            ans.insert(temp);
        }
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};
