class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        // build adj list
        unordered_map<int, vector<pair<int, int>>> adj{};
        for (int i = 0; i < n; i++) {
            adj[i] = vector<pair<int, int>>();
        }

        // s = src, dst = dst, w = weight
        for (vector<int>& edge : edges) {
            int s = edge[0], d = edge[1], w = edge[2];
            adj[s].push_back({d, w});
        }
        
        unordered_map<int, int> res{};
        res.reserve(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq{};
        pq.push({0, src});
        
        while (!pq.empty()) {
            auto [wei, dst] = pq.top(); pq.pop();
            // if we alreayd have it in shrotest continue as it is larger
            if (res.find(dst) != res.end()) continue;
            res[dst] = wei;

            for (auto& [zdst, zwei] : adj[dst]) {
                // only add if we do not have it on our res
                if (res.find(zdst) == res.end()) {
                    pq.push({zwei + wei, zdst});
                }
            }
        }

        // fill in holes
        for (int i = 0; i < n; i++) {
            if (res.find(i) == res.end()) {
                res[i] = -1;
            }
        }
        return res;
    }
};
