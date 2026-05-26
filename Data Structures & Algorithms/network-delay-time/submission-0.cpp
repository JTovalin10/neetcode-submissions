class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        for (int i{0}; i < n - 1; i++) {
            for (const auto& time : times) {
                int src = time[0], dst = time[1], wei = time[2];
                if (dist[src] != INT_MAX && dist[src] + wei < dist[dst]) {
                    dist[dst] = dist[src] + wei;
                }
            }
        }
        int m = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            m = max(m, dist[i]);
        }
        return m;
    }
};
