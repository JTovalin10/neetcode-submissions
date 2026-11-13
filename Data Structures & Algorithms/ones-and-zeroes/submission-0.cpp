class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // pre calculate
        strs_cnt.reserve(strs.size());

        for (const string& str : strs) {
            int zero = 0;
            int one = 0;
            for (char c : str) {
                if (c == '0') zero++;
                else one++;
            }
            strs_cnt.push_back({zero, one});
        }
        max_zero = m;
        max_one = n;

        dp = vector<vector<vector<int>>>(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return dfs(0, 0, 0);
    }

private:
    vector<pair<int, int>> strs_cnt{};
    int max_zero;
    int max_one;
    // idx, curr_zero, curr_one
    vector<vector<vector<int>>>dp{};

    int dfs(int i, const int curr_zero, const int curr_one) {
        if (curr_zero == max_zero && curr_one == max_one) return 0;
        if (i == strs_cnt.size()) return 0;
        if (dp[i][curr_zero][curr_one] != -1) return dp[i][curr_zero][curr_one];

        int without = dfs(i + 1, curr_zero, curr_one);
        auto& [zero, one] = strs_cnt[i];
        int with = 0;
        if (curr_zero + zero <= max_zero && curr_one + one <= max_one) {
            with = 1 + dfs(i + 1, curr_zero + zero, curr_one + one);
        }
        int res = std::max(without, with);
        dp[i][curr_zero][curr_one] = res;
        return res;
    }
};