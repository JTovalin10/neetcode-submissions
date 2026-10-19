class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int l = 0; 
        int max_freq = 0;
        int res = 0;
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            counts[c - 'A']++;

            max_freq = std::max(max_freq, counts[c -'A']);
            // if every other letter that isnt the max_freq > k
            if ((r - l + 1) - max_freq > k) {
                counts[s[l] - 'A']--;
                l++;
            }

            res = std::max(res, r - l + 1);
        }
        return res;
    }
};
