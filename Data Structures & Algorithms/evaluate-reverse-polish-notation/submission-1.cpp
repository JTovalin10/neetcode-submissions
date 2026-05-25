class Solution {
public:
    int evalRPN(const vector<string>& tokens) {
        stack<int> stk{};
        
        for (const string& token : tokens) {
            exec(token, stk);
        }
        int res = stk.top();
        return res;
    }
private:

    void exec(const string& token, stack<int>& stk) {
        if (token == "+") {
            int n1 = stk.top(); stk.pop();
            int n2 = stk.top(); stk.pop();
            stk.push(n1 + n2);
        } else if (token == "-") {
            int n1 = stk.top(); stk.pop();
            int n2 = stk.top(); stk.pop();
            stk.push(n2 - n1);
        } else if (token == "*") {
            int n1 = stk.top(); stk.pop();
            int n2 = stk.top(); stk.pop();
            stk.push(n1 * n2);
        } else if (token == "/") {
            int n1 = stk.top(); stk.pop();
            int n2 = stk.top(); stk.pop();
            stk.push(n2 / n1);
        } else {
            stk.push(stoi(token));
        }
    }
};
