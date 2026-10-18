class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *std::max_element(piles.begin(), piles.end());
        while (l < r) {
            int eaten{};
            int m = l + (r - l) / 2;
            for (const int num : piles) {
                eaten += std::ceil(static_cast<double>(num) / m);
            }

            if (h < eaten) {
                // we are too slow
                l = m + 1;
            } else {
                // we are fast and this is valid so we can keep checking
                r = m;
            }
        }
        return l;
    }
};
