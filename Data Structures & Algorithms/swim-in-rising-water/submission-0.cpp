class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int ROW = grid.size();
        const int COL = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> min_heap{};
        vector<vector<bool>> seen(ROW + 1, vector<bool>(COL + 1, false));
        const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int res = 0;
        min_heap.push({grid[0][0], 0, 0});

        while (!min_heap.empty()) {
            auto [curr, r, c] = min_heap.top(); min_heap.pop();
            if (seen[r][c]) continue;
            seen[r][c] = true;
            res = std::max(res, curr);
            if (r == ROW - 1 && c == COL - 1) break;
            for (const auto& [x, y] : dirs) {
                int dx = r + x;
                int dy = c + y;
                if (dx >= 0 && dy >= 0 && dx < ROW && dy < COL) {
                    min_heap.push({grid[dx][dy], dx, dy});
                }
            }
        }

        return res;
    }
};
