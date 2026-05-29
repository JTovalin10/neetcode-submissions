class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int rob1 = helper(std::vector<int>(nums.begin(), nums.end() - 1));
        int rob2 = helper(std::vector<int>(nums.begin() + 1, nums.end()));
        return std::max(rob1, rob2);
    }

    int helper(const vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = std::max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        return dp.back();
    }
};
