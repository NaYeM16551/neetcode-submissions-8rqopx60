class Solution {
    long long reverse2(int n)
    {
        long long rev = 0;
       while(n)
       {
        rev = 1LL*rev*10 + (n%10);
        n/=10;
       }
       return rev;
    }
public:
    int reverse(int x) {

        //if(x==INT_MIN)return 0;

        auto ans =  reverse2(abs(x))*(x<0 ? -1 : 1);

        if(ans<INT_MIN or ans>INT_MAX)return 0;
        return ans;


        
    }
};
