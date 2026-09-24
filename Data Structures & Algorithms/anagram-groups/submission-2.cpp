class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams{};
        anagrams.reserve(strs.size());

        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++) {
                key += ',' + to_string(count[i]);
            }
            anagrams[key].push_back(s);
        }

        vector<vector<string>> res{};
        for (const auto& pair : anagrams) {
            res.push_back(pair.second);
        }
        return res;
    }
};