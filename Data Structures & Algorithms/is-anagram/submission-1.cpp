class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> s_count{};
        s_count.reserve(26);
        for (char c : s) {
            s_count[c]++;
        }
        unordered_map<char, int> t_count{};
        t_count.reserve(26);
        for (char c : t) {
            t_count[c]++;
        }
        return s_count == t_count;
    }
};
