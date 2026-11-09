class Solution {
public:
    string longestPalindrome(string s) {
        int res_idx = 0;
        int res_length = 0;
        const int SIZE = s.size();
        for (int i = 0; i < SIZE; i++) {
            char curr_char = s[i];

            int l = i, r = i;
            while (l >= 0 && r < SIZE && s[l] == s[r]) {
                if (r - l + 1 > res_length) {
                    res_idx = l;
                    res_length = r - l + 1;
                }
                l--;
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < SIZE && s[l] == s[r]) {
                if (r - l + 1 > res_length) {
                    res_idx = l;
                    res_length = r - l + 1;
                }
                l--;
                r++;
            }
        }
    return s.substr(res_idx, res_length);
    }
};
