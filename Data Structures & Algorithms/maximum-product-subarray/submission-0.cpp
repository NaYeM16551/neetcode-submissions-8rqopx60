class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1,suff = 1;
        int maxProduct = INT_MIN;

        int n = nums.size();

        for(int i=0;i<nums.size();++i)
        {
            pre*=nums[i];
            suff*=nums[n-i-1];

            maxProduct = max({maxProduct,pre,suff});

            if(!pre)pre=1;
            if(!suff)suff=1;
            
            
        }

        return maxProduct;
    }
};
