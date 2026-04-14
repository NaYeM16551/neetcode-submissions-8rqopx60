class Solution {
    int reverseBits32(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
        }
        return (int)ans;
    }

public:
    int getSum(int a, int b) {
        uint32_t x = (uint32_t)a;
        uint32_t y = (uint32_t)b;

        uint32_t ans = 0;
        int carry = 0;

        for (int i = 0; i < 32; ++i) {
            bool isSetA = x & 1;
            bool isSetB = y & 1;

            ans <<= 1;

            if (isSetA && isSetB) {
                ans |= carry;
                carry = 1;
            } 
            else if (isSetA || isSetB) {
                ans |= (1 ^ carry);
            } 
            else {
                ans |= carry;
                carry = 0;
            }

            x >>= 1;
            y >>= 1;
        }

        return reverseBits32(ans);
    }
};