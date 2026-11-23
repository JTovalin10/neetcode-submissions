class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max = nums[0], min = nums[0];
        int curMax = 0, curMin = 0, total = 0;

        for (int num : nums) {
            curMax = std::max(curMax + num, num);
            curMin = std::min(curMin + num, num);
            total += num;
            max = std::max(curMax, max);
            min = std::min(curMin, min);
        }

        return max > 0 ? std::max(max, total - min) : max;
    }
};