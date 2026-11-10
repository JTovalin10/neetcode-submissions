class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(s, wordDict, 0);
    }

private:
    unordered_map<int, bool> seen{};

    bool dfs(const string& s, const vector<string>& wordDict, int i) {
        if (i == s.size()) {
            seen[i] = true;
            return true;
        }
        if (seen.count(i)) return seen[i];

        bool res = false;
        for (const auto& w : wordDict) {
            int size = w.size() + i;
            if (size <= s.size() &&
                s.substr(i, w.size()) == w) {
                    if (dfs(s, wordDict, size)) {
                        seen[i] = true;
                        return true;
                    }
                }
        }
        seen[i] = false;
        return false;
    }
};
