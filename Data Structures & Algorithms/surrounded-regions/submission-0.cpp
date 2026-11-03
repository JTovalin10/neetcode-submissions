class Solution {
public:
    void solve(vector<vector<char>>& board) {
        ROW = board.size();
        COL = board[0].size();
        safe = vector<vector<bool>>(ROW, vector<bool>(COL, false));

        // find all safe spots
        for (int r = 0; r < ROW; r++) {
            dfs(r, 0, board);
            dfs(r, COL - 1, board);
        }
        for (int c = 0; c < COL; c++) {
            dfs(0, c, board);
            dfs(ROW - 1, c, board);
        }

        // filter all non-safe spots
        for (int r{}; r < ROW; r++) {
            for (int c{}; c < COL; c++) {
                if (board[r][c] == 'O' && !safe[r][c]) {
                    board[r][c] = 'X';
                }
            }
        }
    }

private:
    int ROW;
    int COL;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool>> safe;

    void dfs(int r, int c, vector<vector<char>>& board) {
        if (board[r][c] == 'X' || safe[r][c]) return;
        safe[r][c] = true;

        for (const auto& [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr >= 0 && nc >= 0 && nr < ROW && nc < COL && board[nr][nc] == 'O') {
                dfs(nr, nc, board);
            }
        }
    }
};
