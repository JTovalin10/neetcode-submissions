class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            const string& src = ticket[0];
            const string& dst = ticket[1];
            adj[src].push_back(dst);
        }

        for (auto& [src, dsts] : adj) {
            std::sort(dsts.begin(), dsts.end());
        }

        bfs("JFK");
        std::reverse(res.begin(), res.end());
        return res;
    }

private:
    unordered_map<string, deque<string>> adj{};
    vector<string> res{};

    void bfs(const string& src) {
        while (!adj[src].empty()) {
            string dst = adj[src].front();
            adj[src].pop_front();
            bfs(dst);
        }
        res.push_back(src);
    }
};
