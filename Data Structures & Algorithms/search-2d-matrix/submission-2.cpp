class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int row = matrix.size();
        const int col = matrix[0].size();
        int l = 0, r = row * col - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int i = mid / col;
            int j = mid % col;

            int num = matrix[i][j];
            if (num == target) return true;

            if (num < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
