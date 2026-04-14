class Solution {
public:
    int tribonacci(int n) {
        int ans=0;
        if(n<3)
          ans = min(1,n);
        int prev1 = 1,prev2=1,prev3=0;

        for(int i=3;i<=n;++i)
        {
            ans = prev1 + prev2 + prev3;
            prev3= prev2 ;
            prev2 = prev1;
            prev1=ans;
        }
        return ans;
    }
};