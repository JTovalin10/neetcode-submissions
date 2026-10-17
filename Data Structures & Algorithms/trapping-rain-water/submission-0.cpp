class Solution {
public:
    int trap(const vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max_water{0};
        int l_max{};
        int r_max{};
        while (l < r) {
            int l_hei = height[l];
            int r_hei = height[r];
            if (l_hei < r_hei) {
                // work on left
                l_max = std::max(l_max, l_hei);
                max_water += l_max - l_hei;
                l++;
            } else {
                // work on left hei
                r_max = std::max(r_max, r_hei);
                max_water += r_max - r_hei;
                r--;
            }
        }
        return max_water;
    }
};
