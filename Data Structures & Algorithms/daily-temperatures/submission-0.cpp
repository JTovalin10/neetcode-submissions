class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int N = temperatures.size();
        vector<int> res(N, 0);

        stack<int> stk{};
        for (int i{}; i < N; i++) {
            const int temp = temperatures[i];
            while (!stk.empty() && temperatures[stk.top()] < temp) {
                int idx = stk.top(); stk.pop();
                int diff = i - idx;
                res[idx] = diff;
            }
            stk.push(i);
        }
        return res;
    }
};
