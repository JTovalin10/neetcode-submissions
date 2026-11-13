class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0, 0);
    }

private:
    map<pair<int, int>, int> memo{};

    int dfs(const vector<int>& nums, const int target, const int idx, int curr_sum) {
        if (idx == nums.size()) {
            return target == curr_sum ? 1 : 0;
        }
        if (memo.count({idx, curr_sum})) return memo[{idx, curr_sum}];
        int plus = dfs(nums, target, idx + 1, curr_sum + nums[idx]);
        int minus = dfs(nums, target, idx + 1, curr_sum - nums[idx]);
        int res = plus + minus;
        memo[{idx, curr_sum}] = res;
        return res;
    }
};
