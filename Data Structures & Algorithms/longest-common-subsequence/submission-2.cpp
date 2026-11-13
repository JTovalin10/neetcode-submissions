class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int N = text1.size();
        const int M = text2.size();

        const int SMALLER = N < M ? N : M;
        const int BIGGER = N < M ? M : N; // flip what we return so we are guranteed to have opposites
        const string& smaller_string = (N < M ? text1 : text2);
        const string& larger_string = (N < M ? text2 : text1);    


        vector<int> prev(SMALLER, 0);
        for (int b = BIGGER - 1; b >= 0; b--) {
            vector<int> curr(SMALLER, 0);
            for (int s = SMALLER - 1; s >= 0; s--) {
                int bottom = prev[s];
                int right = (s + 1 == SMALLER ? 0 : curr[s + 1]);
                int res;
                if (smaller_string[s] == larger_string[b]) {
                    res = 1 + (s + 1 == SMALLER ? 0 : prev[s + 1]);
                } else {
                    res = std::max(bottom, right);
                }
                curr[s] = res;
            }
            prev = curr;
        }
        return prev[0];
    }
};
