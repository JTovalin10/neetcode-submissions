class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            int preq = pre[0];
            int course = pre[1];
            inDegree[preq]++;
            adj[course].push_back(preq);
        }

        queue<int> q{};
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res{};
        res.reserve(numCourses);
        while (!q.empty() && res.size() < numCourses) {
            int num = q.front(); q.pop();
            res.push_back(num);
            for (const auto& nei : adj[num]) {
                inDegree[nei]--;
                if (inDegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
    }
};
