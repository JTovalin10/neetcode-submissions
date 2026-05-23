class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, vector<pair<int, int>>> adj{};
        for (int i{}; i < n; i++) {
            adj[i] = vector<pair<int, int>>();
        }

        // fill it
        for (const auto& edge : edges) {
            int src = edge[0], dst = edge[1], wei = edge[2];
            adj[src].push_back({dst, wei});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});
        unordered_map<int, int> shortest{};
        shortest.reserve(n);
        
        while (!pq.empty()) {
            auto [ wei, dst ] = pq.top(); pq.pop();

            // if we already have it in shortest
            if (shortest.find(dst) != shortest.end()) continue;
            shortest[dst] = wei;
            for (const auto& [dst2, wei2] : adj[dst]) {
                if (shortest.find(dst2) == shortest.end()) {
                    pq.push({wei + wei2, dst2});
                }
            }
        }

        // fill in gaps
        for (int i{}; i < n; i++) {
            if (shortest.find(i) == shortest.end()) {
                shortest[i] = -1;
            }
        }
        return shortest;
    }
};
