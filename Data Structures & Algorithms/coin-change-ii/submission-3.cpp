class Solution {
public:
    int change(int amount, vector<int>& coins) {
        memo.assign(amount + 1, vector<int>(coins.size(), -1));
        return dfs(amount, coins, 0);
    }

private:
    vector<vector<int>> memo{};

    // invariant: curr >= 0
    int dfs(int curr, const vector<int>& coins, int idx) {
        if (curr == 0) return 1;
        if (idx == coins.size()) return 0;
        if (memo[curr][idx] != -1) return memo[curr][idx];

        int without = dfs(curr, coins, idx + 1);

        int with = -1;
        if (curr - coins[idx] >= 0) {
            with = dfs(curr - coins[idx], coins, idx);
        }
        int res = without + (with != -1 ? with : 0);
        memo[curr][idx] = res;
        return res;
    }
};
