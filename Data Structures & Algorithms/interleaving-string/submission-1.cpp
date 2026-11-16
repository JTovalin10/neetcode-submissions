class Solution {
public:
    bool isInterleave(string& s1, string& s2, string& s3) {
        N = s3.size();
        if (s1.size() + s2.size() != N) return false;
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        memo.assign(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return dfs(0, 0, 0);
    }

private:
    int N;
    string s1;
    string s2;
    string s3;
    vector<vector<int>> memo{};

    bool dfs(int i1, int i2, int i3) {
        if (i1 + i2 == N) return true;
        if (memo[i1][i2] != -1) return memo[i1][i2];

        bool res = false;
        if (i1 + 1 <= s1.size() && s1[i1] == s3[i3]) {
            res |= dfs(i1 + 1, i2, i3 + 1);
        }
        if (i2 + 1 <= s2.size() && s2[i2] == s3[i3]) {
            res |= dfs(i1, i2 + 1, i3 + 1);
        }
        memo[i1][i2] = res;
        return res;
    }
};
