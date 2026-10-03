class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> close_to_open{};
        close_to_open['}'] = '{';
        close_to_open[']'] = '[';
        close_to_open[')'] = '(';

        stack<char> stk{};
        for (char c : s) {
            // c is a close symbol
            if (close_to_open.count(c)) {
                if (stk.empty()) return false;
                if (close_to_open[c] != stk.top()) return false;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};
