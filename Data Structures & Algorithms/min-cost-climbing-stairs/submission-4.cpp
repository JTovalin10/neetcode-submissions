class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int N = cost.size();

        vector<int> dp(N + 1, 0);

        for (int i = 2; i <= N; i++) {
            dp[i] = std::min(dp[i - 1] + cost[i - 1],
                            dp[i - 2] + cost[i - 2]);
        }
        return dp[N];
    }
};
