class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNumber = 0;

        for(auto& num : nums)
        {
            singleNumber^=num;
        }

        return singleNumber;
    }
};
