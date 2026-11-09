class Solution {
public:
    int countSubstrings(string s) {
        const int SIZE = s.size();
        vector<vector<bool>> dp(SIZE, vector<bool>(SIZE, false));

        int res{};
        for (int i = SIZE - 1; i >= 0; i--) {
            for (int j = i; j < SIZE; j++) {
                if (s[i] == s[j] && (
                    j - i + 1 <= 2 || dp[i + 1][j - 1]
                )) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        return res;
    }
};
