class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> anagrams{};
        //anagrams.reserve(strs.size());

        for (const string& str : strs) {
            vector<int> nums(26, 0);
            for (const char c : str) {
                nums[c - 'a']++;
            }
            anagrams[nums].push_back(str); 
        }
        vector<vector<string>> res{};
        for (const auto& [key, value] : anagrams) {
            res.push_back(value);
        }
        return res;
    }
};
