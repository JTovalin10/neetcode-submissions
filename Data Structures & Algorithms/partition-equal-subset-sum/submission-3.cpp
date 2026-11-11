class Solution {
public:
    bool canPartition(const vector<int>& nums) {
        SUM = std::accumulate(nums.begin(), nums.end(), 0);
        const int N = nums.size();
        if (SUM % 2 != 0) return false;

        for (int i = 0; i < N; i++) {
            if (dfs(nums, i, nums[i])) return true;
        }

        return false;
    }

private:
    int SUM;
    map<std::pair<int, int>, int> memo{};
    bool dfs(const vector<int>& nums, int idx, int curr_sum) {
        if (idx == nums.size()) {
            return false;
        }
        if (curr_sum > SUM / 2) return false;
        if (curr_sum == SUM / 2) return true;

        std::pair<int, int> key = {idx, curr_sum};
        if (memo.count(key)) return memo[key];

        for (int i = idx + 1; i < nums.size(); i++) {
            // include and dont include
            if (dfs(nums, i, curr_sum) || dfs(nums, i, curr_sum + nums[i])) {
                memo[key] = true;
                return true;
            }
        }
        memo[key] = false;
        return false;
    }
};
