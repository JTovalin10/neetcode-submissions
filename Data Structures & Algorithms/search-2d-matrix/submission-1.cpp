class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const auto rows = matrix.size(); // rows
        const auto cols = matrix[0].size(); //col
        int l = 0, r = rows * cols - 1; // r has to be on the bottom right
        while (l <= r) {
            int m = l + (r - l) / 2;
            int i = m / cols; // find the row, foudn by dividing by columns
            int j = m % cols; // find the col

            int num = matrix[i][j];
            if (num == target) return true;

            if (num < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return false;
    }
};
