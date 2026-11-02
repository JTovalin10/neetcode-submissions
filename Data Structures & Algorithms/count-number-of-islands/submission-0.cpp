class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count{};
        ROW = grid.size();
        COL = grid[0].size();

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (grid[i][j] == '1') {
                    sink_island(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }

private:
    int ROW;
    int COL;

    void sink_island(int r, int c, vector<vector<char>>& grid) {
        if (r < 0 
                || c < 0 
                || r >= ROW 
                || c >= COL 
                || grid[r][c] == '0'
                ) return;
        grid[r][c] = '0';

        sink_island(r + 1, c, grid);
        sink_island(r - 1, c, grid);
        sink_island(r, c + 1, grid);
        sink_island(r, c - 1, grid);
    }
};
