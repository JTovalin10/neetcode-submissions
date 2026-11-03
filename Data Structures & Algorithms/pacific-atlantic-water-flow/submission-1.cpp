class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROW = heights.size();
        COL = heights[0].size();


        set<pair<int, int>> pacific{};
        set<pair<int, int>> atlantic{};
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
        return merge(std::move(pacific), std::move(atlantic));
    }

private:
    int ROW;
    int COL;

    vector<vector<int>> merge(const set<pair<int, int>>&& pac, const set<pair<int, int>>&& alt) {
        vector<vector<int>> res{};
        res.reserve(pac.size() + alt.size()); // reserve optimistically

        for (const auto& [r, c] : pac) {
            if (alt.count({r, c})) {
                res.push_back({r, c});
            }
        }

        // remove unused memory
        res.shrink_to_fit();
        return res;
    }

    void dfs(int row, int col, set<pair<int, int>>& valid, const vector<vector<int>>& heights) {
        if (row < 0 || col < 0 || row >= ROW || col >= COL || valid.count({row, col})) return;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        valid.insert({row, col});
        int curr_hei = heights[row][col];
        for (const auto& [dr, dc] : dirs) {
            int dx = dr + row, dy = dc + col;
            if (dx >= 0 && dy >= 0 && dx < ROW && dy < COL && heights[dx][dy] >= curr_hei) {
                dfs(dx, dy, valid, heights);
            }
        }
    }
};
