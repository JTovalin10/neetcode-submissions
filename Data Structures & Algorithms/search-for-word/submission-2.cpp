class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        ROW = board.size();
        COL = board[0].size();
        this->board = board;
        this->word = std::move(word);

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (backtrack(i, j)) return true;
            }
        }
        return false;
    }

private:
    int ROW{};
    int COL{};
    vector<vector<char>> board{};
    string word{};

    bool backtrack(int row, int col, int idx = 0) {
        if (std::min(row, col) < 0 ||
            row >= ROW ||
            col >= COL ||
            board[row][col] != word[idx]
            ) return false;
        
        if (idx == word.size() - 1) return true;

        char original = board[row][col];
        board[row][col] = '#';
        idx++;
        bool found =
            backtrack(row + 1, col, idx) ||
            backtrack(row - 1, col, idx) ||
            backtrack(row, col - 1, idx) ||
            backtrack(row, col + 1, idx);
        board[row][col] = original;
        return found;
    }
};
