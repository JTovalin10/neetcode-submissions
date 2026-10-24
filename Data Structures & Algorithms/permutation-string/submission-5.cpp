class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> s1_freq{};
        for (char c : s1) {
            s1_freq[c]++;
        }

        unordered_map<char, int> s2_freq{};
        int l = 0;
        for (int r = 0; r < s2.size(); r++) {
            char c = s2[r];

            if (s1_freq.count(c)) {
                s2_freq[c]++;
                if (s2_freq == s1_freq) return true;

                while (s2_freq[c] > s1_freq[c]) {
                    s2_freq[s2[l++]]--;
                }
            } else {
                // if we just dont have it then the entire part is invalid
                l = r + 1;
                s2_freq.clear();
            }
        }

        return false;
    }
};
