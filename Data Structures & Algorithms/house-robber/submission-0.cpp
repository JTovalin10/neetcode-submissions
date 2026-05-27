class Solution {
public:
    int rob(vector<int>& nums) {
        return dfs(0, nums);
    }

private:
    unordered_map<int, int> memo{};

    int dfs(int i, const vector<int>& nums) {
        if (i >= nums.size()) return 0;
        if (i == nums.size()) return nums[i];
        if (memo.count(i)) return memo[i];
        memo[i] = std::max(dfs(i + 1, nums), nums[i] + dfs(i + 2, nums));
        return memo[i];
    }
};
