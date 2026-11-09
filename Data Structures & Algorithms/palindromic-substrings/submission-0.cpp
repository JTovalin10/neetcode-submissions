class Solution {
public:
    int countSubstrings(string s) {
        const int SIZE = s.size();
        vector<vector<bool>> dp(SIZE, vector<bool>(SIZE, false));

        for (int i = SIZE - 1; i >= 0; i--) {
            for (int j = i; j < SIZE; j++) {
                if (s[i] == s[j] && (
                    j - i + 1 <= 2 || dp[i + 1][j - 1]
                )) {
                    dp[i][j] = true;
                }
            }
        }

        // get the count
        int res{};
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                if (dp[i][j]) res++;
            }
        }
        return res;
    }
};
