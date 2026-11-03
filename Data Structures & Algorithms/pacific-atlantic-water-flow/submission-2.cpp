class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROW = heights.size();
        COL = heights[0].size();


        vector<vector<bool>> pacific(ROW, vector<bool>(COL, false));
        vector<vector<bool>> atlantic(ROW, vector<bool>(COL, false));
        // go through the pacific ones first
        for (int r{}; r < ROW; r++) {
            // do dfs on all of these
            dfs(r, 0, pacific, heights);
            dfs(r, COL - 1, atlantic, heights);
        }

        for (int c{}; c < COL; c++) {
            dfs(0, c, pacific, heights);
            dfs(ROW - 1, c, atlantic, heights);
        }
        
        vector<vector<int>> res{};
        res.reserve(pacific.size() + atlantic.size()); // reserve optimistically

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        res.shrink_to_fit();
        return res;
    }

private:
    int ROW;
    int COL;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int row, int col, vector<vector<bool>>& valid, const vector<vector<int>>& heights) {
        valid[row][col] = true;

        int curr_hei = heights[row][col];
        for (const auto& [dr, dc] : dirs) {
            int dx = dr + row, dy = dc + col;
            if (dx >= 0 && dy >= 0 && dx < ROW && dy < COL && !valid[dx][dy] && heights[dx][dy] >= curr_hei) {
                dfs(dx, dy, valid, heights);
            }
        }
    }
};
