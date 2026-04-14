class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();

        if(n==1)return nums[0];

        int l=0,h=n-1;

        int ans=-1;

        while(l<=h)
        {
            int mid = l + (h-l)/2;

           if (nums[mid] <= nums[(mid - 1 + n)%n] and nums[(mid + 1)%n] >= nums[mid])
               return nums[mid];
            else if(nums[mid]>=nums[l] and nums[mid]<=nums[h])
              h=mid-1;


            else if(nums[l]<=nums[mid])
              l=mid+1;
            else
              h=mid-1;  
        }

        return ans;
    }
};
