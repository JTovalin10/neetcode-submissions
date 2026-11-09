class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(amount, coins);
        return minCoins == INT_MAX ? -1 : minCoins;
    }

private:
    unordered_map<int, int> memo{};

    int dfs(int amt, const vector<int>& coins) {
        if (amt == 0) return 0;
        if (memo.find(amt) != memo.end()) return memo[amt];

        int res = INT_MAX;
        for (int coin : coins) {
            if (amt - coin >= 0) {
                int next = dfs(amt - coin, coins);
                if (next == INT_MAX) continue;
                res = std::min(1 + next, res);
            }
        }
        memo[amt] = res;
        return res;
    }
};
