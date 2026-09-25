class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<pair<int, int>, unordered_set<char>> box{};
        unordered_map<int, unordered_set<char>> row, col;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                const char c = board[i][j];
                if (c == '.') continue;

                const pair key = {i / 3, j / 3};
                if (box[key].count(c) || row[i].count(c) || col[j].count(c)) {
                    return false;
                }

                row[i].insert(c);
                col[j].insert(c);
                box[key].insert(c);
            }
        }
        return true;
    }
};