class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (memo.count(i)) {
                res = std::max(memo[i], res);
            } else {
                res = std::max(res, dfs(nums, i));
            }
        }
        return res;
    }

private:
    unordered_map<int, int> memo{};

    int dfs(const vector<int>& nums, int idx) {
        if (nums.size() == idx) {
            memo[idx] = 1;
            return memo[idx];
        }

        if (memo.count(idx)) return memo[idx];
        int res = 1;
        for (int i = idx + 1; i < nums.size(); i++) {
            if (nums[idx] < nums[i]) {
                res = std::max(res, 1 + dfs(nums, i));
            }
        }
        memo[idx] = res;
        return memo[idx];
    }
};
