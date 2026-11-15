class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // create the adj
        // create the inDegree
        unordered_map<int, vector<int>> adj{};
        unordered_map<int, int> inDegree{};
        unordered_map<int, unordered_set<int>> final{};
        final.reserve(numCourses);
        adj.reserve(numCourses);
        inDegree.reserve(numCourses);
        for (const auto& preq : prerequisites) {
            int pre = preq[0];
            int course = preq[1];
            adj[pre].push_back(course);
            inDegree[course]++;
        }

        queue<int> q{};
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        unordered_set<int> seen{};
        seen.reserve(numCourses);
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            if (seen.count(curr)) continue;
            seen.insert(curr);
            
            for (int nei : adj[curr]) {
                inDegree[nei]--;
                final[nei].insert(curr);
                final[nei].insert(final[curr].begin(), final[curr].end());
                if (inDegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // loop through prerequisites to find if pre[i][0] is a preq of pre[i][1] 
        vector<bool> res{};
        res.reserve(queries.size());
        for (const auto& query : queries) {
            int target = query[0];
            int src = query[1];
            res.push_back(final[src].count(target));
        }
        return res;
    }

private:
    
};