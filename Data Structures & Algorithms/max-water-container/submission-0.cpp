class Solution {
public:
    int maxArea(const vector<int>& heights) {
        const auto length = heights.size();
        if (length < 1) return 0;
        int l = 0, r = length - 1;
        int max_water{};
        while (l < r) {
            max_water = std::max(max_water, area(l, r, heights));
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_water;
    }

private:

int area(int l, int r, const vector<int>& heights) {
    int min_height = std::min(heights[l], heights[r]);
    int length = r - l;
    return min_height * length;
}
};
