class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // num -> count
        unordered_map<int, int> counts{};
        counts.reserve(nums.size());
        for (const int num : nums) {
            counts[num]++;
        }

        // count -> nums
        unordered_map<int, vector<int>> bucket{};
        bucket.reserve(counts.size());
        for (const auto& [num, count] : counts) {
            bucket[count].push_back(num);
        }
        // populate the result
        vector<int> res{};
        res.reserve(k);
        for (int i = nums.size(); i >= 0; i--) {
            if (bucket.count(i)) {
                for (const int num : bucket[i]) {
                    res.push_back(num);
                    if (res.size() == k) return res;
                }
            }
        }
         return res;
    }
};
