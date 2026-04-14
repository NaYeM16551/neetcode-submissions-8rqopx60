class Solution {

    bool isValid(int rate,vector<int>& piles, int h)
    {
        int totalHour=0;

        for(auto& pile : piles)
        {
            totalHour+=((pile+rate-1)/rate);
            if(totalHour>h)return false;
        }

        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high = *max_element(piles.begin(),piles.end());

        int ans=-1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(isValid(mid,piles,h))
            {
                ans=mid;
                high=mid-1;
            }
            else
              low=mid+1;
        }

        return ans;


    }
};
