class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const auto N = temperatures.size();
        vector<int> res(N);
        stack<int> prev{};
        for (int i = 0; i < N; i++) {
            int temp = temperatures[i];
            while (!prev.empty() && temp > temperatures[prev.top()]) {
                int o_index = prev.top(); prev.pop();
                res[o_index] = i - o_index;
            }
            prev.push(i);
        }
        return res;
    }
};
