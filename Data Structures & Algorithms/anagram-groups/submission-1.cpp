class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res{};
        res.reserve(strs.size());

        for (const auto& str : strs) {
            vector<int> nums(26, 0);
            for (const char c : str) {
                nums[c - 'a']++;
            }

            string key{};
            for (int i{}; i < 26; i++) {
                key += ',' + to_string(nums[i]);
            }
            res[key].push_back(str);
        }

        vector<vector<string>> result{};
        result.reserve(res.size());
        for (const auto& [key, value] : res) {
            result.push_back(value);
        }
        return result;
    }
};
