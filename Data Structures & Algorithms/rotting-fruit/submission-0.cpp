class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();

        // find the rotton banana
        queue<pair<int, int>> q{};
        set<pair<int, int>> fresh{};
        for (int r{}; r < N; r++) {
            for (int c{}; c < M; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    fresh.insert({r, c});
                }
            }
        }

        // now we want to go through each one and find the it takes to make all of them rotten
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int time{0};
        while (!q.empty() && !fresh.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                const auto [r, c] = q.front(); q.pop();

                for (const auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = dc + c;

                    if (nr >= 0 && nc >= 0 && nr < N && nc < M && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh.erase({nr, nc});
                        q.push({nr, nc});
                    }
                }
            }
            time++;
        }

        return fresh.size() > 0 ? -1 : time;
    }
};
