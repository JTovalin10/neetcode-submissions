class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {        
        adj.reserve(tickets.size());
        for (auto& ticket : tickets) {
            const auto& src = ticket[0];
            const auto& dst = ticket[1];
            adj[src].push_back(dst);
        }

        for (auto& [src, dsts] : adj) {
            std::sort(dsts.begin(), dsts.end());
        }

        dfs("JFK");
        std::reverse(res.begin(), res.end());
        return res;
    }

private:
    unordered_map<string, deque<string>> adj{};
    vector<string> res{};

        void dfs(const string& src) {
            while (!adj[src].empty()) {
                string dst = adj[src].front();
                adj[src].pop_front();
                dfs(dst);
            }
            res.push_back(src);
        }
};