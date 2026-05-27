class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int c1 = dfs(0, cost);
        //memo.clear();
        int c2 = dfs(1, cost);
        return std::min(c1, c2);
    }

private:
    unordered_map<int, int> memo{};

    int dfs(int i, const vector<int>& cost) {
        if (i > cost.size()) return INT_MAX;
        if (i == cost.size()) return 0;
        if (memo.count(i)) return memo[i];
        memo[i] = cost[i] + std::min(dfs(i + 1, cost), dfs(i + 2, cost));
        return memo[i];
    }
};
