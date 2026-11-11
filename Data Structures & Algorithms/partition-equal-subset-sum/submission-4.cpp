class Solution {
public:
    bool canPartition(const vector<int>& nums) {
        SUM = std::accumulate(nums.begin(), nums.end(), 0);
        if (SUM % 2 != 0) return false;

        // idx, sum
        // -1 represents invisited
        memo.assign(nums.size(), vector<int>(SUM / 2 + 1, -1));
        return dfs(nums, 0, 0);
    }

private:
    int SUM;
    // -1 = invisited
    // 0 = invalid (casts to false)
    // 1 = valid (casts to true)
    vector<vector<int>> memo{};
    bool dfs(const vector<int>& nums, int idx, int curr_sum) {
        if (idx == nums.size()) {
            return false;
        }
        if (curr_sum > SUM / 2) return false;
        if (curr_sum == SUM / 2) return true;

        int val = memo[idx][curr_sum];
        if (val != -1) return val;

        bool res = false;
        for (int i = idx + 1; i < nums.size(); i++) {
            // include and dont include
            if (dfs(nums, i, curr_sum) || dfs(nums, i, curr_sum + nums[i])) {
                res = true;
                break;
            }
        }
        
        memo[idx][curr_sum] = res;
        return memo[idx][curr_sum];
    }
};
