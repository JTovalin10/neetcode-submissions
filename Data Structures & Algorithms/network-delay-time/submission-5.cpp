class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj{};
        adj.reserve(n);
        for (const auto& time : times) {
            int src = time[0];
            int dst = time[1];
            int wei = time[2];
            adj[src].push_back({dst, wei});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq{};
        pq.push({0, k});
        unordered_set<int> seen{};
        int min_time = 0;
        while (!pq.empty()) {
            const auto [w1, src] = pq.top(); pq.pop();

            if (seen.count(src)) continue;

            min_time = w1;
            seen.insert(src);
            for (const auto& nei : adj[src]) {
                const auto [dst, w2] = nei;
                if (!seen.count(dst)) {
                    pq.push({w1 + w2, dst});
                }
            }
        }
        return seen.size() == n ? min_time : -1;
    }
};
