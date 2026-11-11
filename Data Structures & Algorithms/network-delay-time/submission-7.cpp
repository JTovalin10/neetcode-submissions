class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // src -> {dst, wei}
        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
        for (int i = 0; i < times.size(); i++) {
            vector<int>& time = times[i];
            int src = time[0];
            int dst = time[1];
            int wei = time[2];
            adj[src].push_back({dst, wei});
        }

        int min = 0;
        unordered_set<int> seen{};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap{};
        min_heap.push({0, k});

        while (!min_heap.empty()) {
            auto [time, node] = min_heap.top(); min_heap.pop();
            if (seen.count(node)) continue;
            seen.insert(node);
            min = time;
            for (auto& vec : adj[node]) {
                int dst = vec.first;
                int t = vec.second;
                min_heap.push({t + time, dst});
            }
        }
        return seen.size() == n ? min : -1;
    }
};
