class Solution {
    int solve(vector<int>& nums,int startIdx,int endIdx) {
        int numberOfHouse = (endIdx-startIdx+1);

        if (numberOfHouse <= 2)
            return max(nums[startIdx], nums[min(1 + startIdx ,startIdx+numberOfHouse - 1)]);

       int  best_0=nums[startIdx];
       int  best_1=max(nums[startIdx],nums[1+startIdx]);

        int ans = 0;

        for(int i=2+startIdx;i<=endIdx;++i)
        {
            ans = max(best_1,nums[i]+best_0);
            best_0=best_1;
            best_1=ans;
        }

        return best_1;
    }
public:
    int rob(vector<int>& nums) {

        vector<int> case1,case2;

        int n = nums.size();

        if(n==1)return nums[0];

        // for(int i=1;i<n;++i)
        //   case2.push_back(nums[i]);

        // for(int i=0;i<(int)n-1;++i)
        //    case1.push_back(nums[i]);

        return max(solve(nums,0,n-2),solve(nums,1,n-1));
        
    }
};
