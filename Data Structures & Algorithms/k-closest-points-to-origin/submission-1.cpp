class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> max_heap{};
        for (const auto& vec : points) {
            int x = vec[0];
            int y = vec[1];
            int diff = x * x + y * y;
            max_heap.push({diff, {x, y}});
            if (max_heap.size() > k) max_heap.pop();
        }

        vector<vector<int>> res{};
        while (k > 0 && !max_heap.empty()) {
            const auto [diff, cord] = max_heap.top(); max_heap.pop();
            res.push_back({cord.first, cord.second});
            k--;
        }
        return res;
    }
};
