class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return std::min(min_cost(cost, 0), min_cost(cost, 1));
    }

private:
    unordered_map<int, int> memo{};
    int min_cost(const vector<int>& cost, int idx) {
        if (idx >= cost.size()) return 0;
        if (memo.count(idx)) return memo[idx];
        memo[idx] = cost[idx] + std::min(min_cost(cost, idx + 1), min_cost(cost, idx + 2));
        return memo[idx];
    }
};
