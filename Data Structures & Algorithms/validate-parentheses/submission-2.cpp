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
                // it is closed so the stack must have an open one
                if (stk.empty() || stk.top() != close_to_open[c]) {
                    return false;
                } else {
                    stk.pop();
                }
            } else {
                // it is open so ensure the top doesnt contain a closed before adding it
                stk.push(c);
            }
        }
        return stk.empty();
    }
};
