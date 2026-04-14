class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto& num : nums)
          mp[num]++;
        for(auto entry : mp)
        {
            if(entry.second==1)return entry.first;
        }  

        return 0;
        
    }
};
