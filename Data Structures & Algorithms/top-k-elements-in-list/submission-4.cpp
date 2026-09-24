class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq{}; // num -> cnt
        for (int num : nums) {
            freq[num]++;
        }

        unordered_map<int, vector<int>> cnts{}; // cnt -> [nums]
        for (const auto& [num, cnt] : freq) {
            cnts[cnt].push_back(num);
        }
        vector<int> res{};
        for (auto i = nums.size(); i >= 0; i--) {
            for (const auto& num : cnts[i]) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
