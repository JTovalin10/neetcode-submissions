class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const auto N = nums.size();
        unordered_map<int, int> freq{}; // num -> cnt
        freq.reserve(N);
        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> cnts(N + 1); // cnt -> [nums]
        cnts.reserve(N);
        for (const auto& [num, cnt] : freq) {
            cnts[cnt].push_back(num);
        }
        vector<int> res{};
        res.reserve(k);
        for (int i = nums.size(); i > 0; --i) {
            for (int num : cnts[i]) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
