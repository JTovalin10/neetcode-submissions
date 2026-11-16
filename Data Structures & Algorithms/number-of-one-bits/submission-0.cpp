class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        const auto BITS = 32;
        for (int i = 0; i < BITS; i++) {
            res += (n & 1);
            n = n >> 1;
        }
        return res;
    }
};
