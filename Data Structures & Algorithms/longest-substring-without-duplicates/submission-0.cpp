class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen{};
        int l = 0, r = 0;
        int res{};
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            // if we have seen
            while (seen.count(c)) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(c);
            r++;
            res = std::max(res, r - l);
        }
        return res;
    }
};
