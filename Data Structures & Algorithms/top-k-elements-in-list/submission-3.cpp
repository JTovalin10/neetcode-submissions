class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // num -> cnt
        unordered_map<int, int> freq{};
        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap{};
        for (const auto& [num, cnt] : freq) {
            minHeap.push({cnt, num});
            if (minHeap.size() > k) minHeap.pop();
        }

        vector<int> res{};
        for (int i = 0; i < k; i++) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};
