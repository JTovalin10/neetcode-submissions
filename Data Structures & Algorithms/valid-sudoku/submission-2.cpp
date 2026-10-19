class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // to check row and col
        unordered_map<int, unordered_set<char>> row{}, col;
        // to check block
        map<pair<int, int>, unordered_set<char>> square{};

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board.size(); c++) {
                if (board[r][c] == '.') continue;

                char tile = board[r][c];

                pair<int, int> key = {r / 3, c / 3};

                if (square[key].count(tile) || row[r].count(tile) || col[c].count(tile)) return false;

                square[key].insert(tile);
                row[r].insert(tile);
                col[c].insert(tile);
            }
        }
        return true;
    }
};
