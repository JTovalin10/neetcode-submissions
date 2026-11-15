class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        max_sum = std::accumulate(stones.begin(), stones.end(), 0);
        target = std::ceil(max_sum / 2);
        memo.assign(stones.size(), vector<int>(target + 1, -1));
        return dfs(stones, 0, 0);
    }

private:
    int max_sum;
    int target;
    vector<vector<int>> memo{};

    int dfs(const vector<int>& stones, int idx, int cumm) {
        if (idx == stones.size() || cumm >= target) {
            return std::abs(cumm - (max_sum - cumm));
        }
        if (memo[idx][cumm] != -1) return memo[idx][cumm];

        int res = std::min(dfs(stones, idx + 1, cumm), dfs(stones, idx + 1, cumm + stones[idx]));
        memo[idx][cumm] = res;
        return res;
    }
};