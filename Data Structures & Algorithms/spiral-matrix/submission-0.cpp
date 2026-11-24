class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int bottom = 0, top = matrix.size();
        int left = 0, right = matrix[0].size();
        vector<int> res{};
        res.reserve(top * right + 1);
        while (left < right && bottom < top) {
            // grabbing each level at the bottom of the matrix
            for (int i = left; i < right; i++) {
                res.push_back(matrix[bottom][i]);
            }
            bottom++;

            // grab the level for the right
            for (int i = bottom; i < top; i++) {
                res.push_back(matrix[i][right - 1]);
            }
            right--;
            if (!(left < right && bottom < top)) break; 

            // grabbing each level at the top of the matrix
            for (int i = right - 1; i >= left; i--) {
                res.push_back(matrix[top - 1][i]);
            }
            top--;

            // grab the level for the right
            for (int i = top - 1; i >= bottom; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};