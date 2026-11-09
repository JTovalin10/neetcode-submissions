class Solution {
public:
    int numDecodings(string s) {
        const int N = s.size();
        vector<int> dp(N + 1);
        dp[N] = 1;
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i + 1 < N && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
};
