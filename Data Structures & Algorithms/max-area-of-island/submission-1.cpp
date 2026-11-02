class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area{};
        ROW = grid.size();
        COL = grid[0].size();

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (grid[r][c] == 1) {
                    int area = find_area(grid, r, c);
                    max_area = std::max(area, max_area); 
                }
            }
        }
        return max_area;
    }

private:
    int ROW;
    int COL;

    int find_area(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= ROW || c >= COL || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;
        int area = 0;
        area += find_area(grid, r + 1, c);
        area += find_area(grid, r - 1, c);
        area += find_area(grid, r, c + 1);
        area += find_area(grid, r, c - 1);
        return area + 1;
    }
};
