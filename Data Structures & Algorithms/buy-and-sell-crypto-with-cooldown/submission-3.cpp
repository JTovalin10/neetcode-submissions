class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 0 = sell
        // 1 = buy
        memo.assign(2, vector<int>(prices.size(), -1));
        return dfs(prices, State::Buy);
    }

private:
    vector<vector<int>> memo{};

    enum class State {
        Sell = 0,
        Buy = 1,
    };

    int dfs(const vector<int>& prices, State state, int idx = 0) {
        if (idx >= prices.size()) return 0;
        if (memo[static_cast<int>(state)][idx] != -1) return memo[static_cast<int>(state)][idx];

        int res;
        if (state == State::Buy) {
            int buy1 = -prices[idx] + dfs(prices, State::Sell, idx + 1);
            int buy2 = dfs(prices, State::Buy, idx + 1);
            res = std::max(buy1, buy2);
        } else {
            int sell1 = prices[idx] + dfs(prices, State::Buy, idx + 2);
            int sell2 = dfs(prices, State::Sell, idx + 1);
            res = std::max(sell1, sell2);
        }
        memo[static_cast<int>(state)][idx] = res;
        return res;
    }
};
