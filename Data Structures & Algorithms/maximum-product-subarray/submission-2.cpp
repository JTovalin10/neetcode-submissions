class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = 1, curMin = 1;
        for (int num : nums) {
            int tmp = curMax * num; // save the current
            // we want to grab the new max
            // curMax * num will become the new max if num > 0
            // curMin * num = new max if curMin < 0 && num < 0
            // num will be the max if we ended at 0
            curMax = std::max(std::max(tmp, curMin * num), num);
            // we are holding the min for negative numbers
            curMin = std::min(std::min(tmp, curMin * num), num);
            res = std::max(curMax, res);
        }
        return res;
    }
};
