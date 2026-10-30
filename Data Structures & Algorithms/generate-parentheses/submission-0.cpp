class Solution {
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        std::string curr;
        backtrack(curr);
        return res;
    }

private:
    vector<string> res{};
    int n{};

    void backtrack(std::string& curr, int open = 0, int closed = 0) {
        if (open == n && closed == n) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            backtrack(curr, open + 1, closed);
            curr.pop_back();
        }
        if (closed < open) {
            curr.push_back(')');
            backtrack(curr, open, closed + 1);
            curr.pop_back();
        }
    }
};
