class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();

        // r, c position of 0's
        queue<pair<int, int>> q{};
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if(grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        // do a bfs on the cords
        int level = 0;
        vector<pair<int, int>> pairs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                const auto [r, c] = q.front(); q.pop();
                
                for (const auto& [nr, nc] : pairs) {
                    int dx = nr + r;
                    int dy = nc + c;
                    if (dx >= 0 && dy >= 0 && dx < ROW && dy < COL && grid[dx][dy] == INT_MAX) {
                        grid[dx][dy] = level + 1;
                        q.push({dx, dy});
                    }
                }
            }
            level++;
        }
    }
};
