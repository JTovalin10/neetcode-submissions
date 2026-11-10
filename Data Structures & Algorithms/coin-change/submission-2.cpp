class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins, amount);
        return res == INT_MAX ? -1 : res;
    }

private:
    unordered_map<int, int> memo{};
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (memo.count(amount)) return memo[amount];
        int res = INT_MAX;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                int amt = dfs(coins, amount - coin);
                if (amt == INT_MAX) continue;
                res = std::min(res, amt + 1);
            }
        }
        memo[amount] = res;
        return res;
    }
    
};
