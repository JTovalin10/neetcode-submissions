class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // (pos, time-to-reach-end)
        const int SIZE = position.size();
        vector<pair<int, double>> til_end{};
        til_end.reserve(SIZE);
        for (int i = 0; i < SIZE; i++) {
            int pos = position[i];
            int spd = speed[i];
            double tte = static_cast<double>(target - pos) / spd;
            til_end.push_back({pos, tte});
        }
        std::sort(til_end.begin(), til_end.end(), [](pair<int, double> a, pair<int, double> b) { 
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        });
        // we are now looping where the car that will reach the end first will be processed first
        stack<double> stk{};
        stk.push(til_end[0].second);
        for (const auto& [pos, tte] : til_end) {
            // only add if the tte is more as that means they will never make a fleet
            if (tte > stk.top()) {
                stk.push(tte);   
            }
        }
        return stk.size();

    }
};
