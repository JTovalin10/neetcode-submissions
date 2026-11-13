class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        ROW = m;
        COL = n;
        return dfs(grid, 0, 0);
    }
private:
    int ROW;
    int COL;

    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= ROW || col >= COL) return 0;
        if (row == ROW - 1 && col == COL - 1) return 1;
        if (grid[row][col] != -1) return grid[row][col];

        int res = 0;
        res += dfs(grid, row + 1, col);
        res += dfs(grid, row, col + 1);
        grid[row][col] = res;
        return res;
    }
};
