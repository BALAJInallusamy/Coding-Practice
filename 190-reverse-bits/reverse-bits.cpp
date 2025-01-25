class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int x = 31;
        while(x--){
                ans = ans | (n&1);
                n = n>>1;
                ans = ans<<1;
        }
        return ans|(n&1);
    }
};
// 11010
// 1