class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         unordered_map<char, int> freq{};
         for (char c : s1) {
            freq[c]++;
         }

        unordered_map<char, int> cfreq{};
        int l = 0;
        const int N = s1.size();
        for (int r = 0; r < s2.size(); r++) {
            char c = s2[r];
            if (freq.count(c)) {
                cfreq[c]++;
                if (cfreq == freq) return true;
                while (cfreq[c] > freq[c]) {
                    cfreq[s2[l]]--;
                    l++;
                }
            } else {
                // we cannot continue so reset
                cfreq.clear();
                l = r;
            }
        }
        return false;
    }
};
