class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // (x, y) -> char
        map<pair<int, int>, unordered_set<char>> block;
        // x or y -> char
        unordered_map<int, unordered_set<char>> row, col;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                char num = board[i][j];

                if (num == '.') continue;

                pair key = {i / 3, j / 3};

                if (row[i].count(num) ||
                    col[j].count(num) ||
                    block[key].count(num)
                    ) {
                    return false;
                }

                row[i].insert(num);
                col[j].insert(num);
                block[key].insert(num);
            }        
        } 
        return true;
    }
};
