class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *std::max_element(piles.begin(), piles.end());
        while (l < r) {
            int m = l + (r - l) / 2;
            uint64_t hrs = 0;
            for (int num : piles) {
                hrs += std::ceil(static_cast<double>(num) / static_cast<double>(m));
            }

            if (hrs > h) {
                // too slow
                l = m + 1;
            } else {
                // we are within bound and m is valid
                r = m;
            }
        }
        return l;
    }
};
