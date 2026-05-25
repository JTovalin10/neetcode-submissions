class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> close_to_open{};
        close_to_open.reserve(3);
        close_to_open[')'] = '(';
        close_to_open['}'] = '{';
        close_to_open[']'] = '[';

        stack<char> stk{};
        for (const char c : s) {
            if (close_to_open.count(c)) {
                if (stk.empty()) return false;
                if (close_to_open[c] == stk.top()) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};
