class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // src -> list(dst, time)
        unordered_map<int, vector<pair<int, int>>> adj{};
        adj.reserve(n);
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int t = time[2];
            adj[u].push_back({v, t});
        }

        // make a minheap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap{};
        minHeap.push({0, k});
        // set to keep track of what we have seen
        unordered_set<int> seen{};
        int res = 0;
        while (!minHeap.empty()) {
            const auto [cost, node] = minHeap.top(); minHeap.pop();
            if (seen.contains(node)) continue;
            seen.insert(node);
            res = cost;
            if (!adj.count(node)) continue;
            for (const auto& [dst, cnt2] : adj[node]) {
                if (!seen.contains(dst)) {
                    minHeap.push({cost + cnt2, dst});
                }
            }
        }
        return seen.size() == n ? res : -1;
    }
};
