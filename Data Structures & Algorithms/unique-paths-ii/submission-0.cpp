class Solution {
public:
    int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) {
        const int N = obstacleGrid.size();  
        const int M = obstacleGrid[0].size();
        vector<int> prev(N, 0);
        prev[N - 1] = 1;
        for (int col = M - 1; col >= 0; col--) {
            vector<int> curr(N, 0);
            for (int row = N - 1; row >= 0; row--) {
                int num = obstacleGrid[row][col];
                if (num == 1) continue;

                //if (row > 0 && col > 0 && obstacleGrid[row - 1][col] == 1 && obstacleGrid[row][col - 1] == 1) continue;
                if (row + 1 != N) {
                    curr[row] += curr[row + 1];
                }
                curr[row] += prev[row];
            }
            prev = curr;
        }
        return prev[0];
    }
};