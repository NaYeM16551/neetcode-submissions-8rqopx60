class Solution {
    int solve(vector<int>& nums) {
        int numberOfHouse = nums.size();

        if (numberOfHouse <= 2)
            return max(nums[0], nums[min(1, numberOfHouse - 1)]);

        

       // vector<int> best(numberOfHouse, -1);

       int  best_0=nums[0];
       int  best_1=max(nums[0],nums[1]);

        int ans = 0;

        for(int i=2;i<numberOfHouse;++i)
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

        for(int i=1;i<n;++i)
          case2.push_back(nums[i]);

        for(int i=0;i<(int)n-1;++i)
           case1.push_back(nums[i]);

        return max(solve(case1),solve(case2));
        
    }
};
