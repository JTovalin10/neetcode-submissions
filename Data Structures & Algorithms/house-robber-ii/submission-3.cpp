class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return std::max(dp(nums, 0, nums.size() - 1), dp(nums, 1, nums.size()));
    }

private:
    int dp(const vector<int>& nums, int l, int r) {
        int rob1 = 0, rob2 = 0;
        for (int i = l; i < r; i++) {
            int tmp = rob2;
            rob2 = std::max(rob1 + nums[i], rob2);
            rob1 = tmp;
        }
        return rob2;
    }
};
