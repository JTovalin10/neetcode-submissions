class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ROW = matrix.size();
        COL = matrix[0].size();
        dp.assign(ROW + 1, vector<int>(COL + 1, -1));

        int res = 1;
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                res = std::max(res, dfs(matrix, r, c, -1));
            }
        }
        return res;
    }

private:
    vector<vector<int>> dp{};
    int ROW;
    int COL;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int dfs(const vector<vector<int>>& matrix, int i, int j, int prev) {
        if (matrix[i][j] <= prev) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int res = 1;
        for (const auto& [x, y] : dirs) {
            int dx = x + i;
            int dy = y + j;
            if (dx >= 0 && dx < ROW && dy >= 0 && dy < COL) {
                res = std::max(res, 1 + dfs(matrix, dx, dy, matrix[i][j]));
            }
        }

        dp[i][j] = res;
        return res;
    }
};
