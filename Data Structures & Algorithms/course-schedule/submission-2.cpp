class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (const auto& vec : prerequisites) {
            int course = vec[0];
            int pre = vec[1];
            indegree[pre]++;
            // course -> pre
            adj[course].push_back(pre);
        }

        queue<int> q{};
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count{};
        while (!q.empty()) {
            int item = q.front(); q.pop();
            count++;
            for (const auto& num : adj[item]) {
                indegree[num]--;
                if (indegree[num] == 0) {
                    q.push(num);
                }
            }
        }
        return count == numCourses;
    }
};
