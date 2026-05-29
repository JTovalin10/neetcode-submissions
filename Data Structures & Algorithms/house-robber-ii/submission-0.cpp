class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        memo.clear();
        int rob1 = dfs(0, nums, nums.size() - 2);
        memo.clear();
        int rob2 = dfs(1, nums, nums.size() - 1);
        return std::max(rob1, rob2);
    }

private:

    unordered_map<int, int> memo{};

    int dfs(int i, const vector<int>& nums, int end) {
        if (i > end) return 0;
        if (i == end) return nums[i];
        if (memo.count(i)) return memo[i];
        memo[i] = std::max(dfs(i + 1, nums, end), nums[i] + dfs(i + 2, nums, end));
        return memo[i];
    }
};