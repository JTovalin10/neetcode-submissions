class Solution {
public:
    string longestPalindrome(string s) {
        const int SIZE = s.size();
        vector<vector<bool>> dp(SIZE, vector<bool>(SIZE, false));
        int idx = 0, len = 0;

        for (int i = SIZE - 1; i >= 0; i--) {
            for (int j = i; j < SIZE; j++) {
                if (s[i] == s[j] &&
                (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;

                    if (j - i + 1 > len) {
                        len = j - i + 1;
                        idx = i;
                    }
                }
            }
        }
        return s.substr(idx, len);
    }
};
