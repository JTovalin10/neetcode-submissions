class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // idx1, {wei, idx2}
        unordered_map<int, vector<pair<int, int>>> adj{};
        for (int i = 0; i < points.size(); i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < points.size(); j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = std::abs(x2 - x1) + std::abs(y2 - y1);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap{};

        // wei, idx
        min_heap.push({0, 0});
        int res = 0;
        unordered_set<int> seen{};
        while (!min_heap.empty()) {
            auto [cost, idx] = min_heap.top(); min_heap.pop();
            if (seen.count(idx)) continue;
            res += cost;
            seen.insert(idx);
            for (const auto& [wei, n_idx] : adj[idx]) {
                min_heap.push({wei, n_idx});
            } 
        }
        return res;
    }
};
