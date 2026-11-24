class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // edge case to ensure everything past this is valid
        const int SUM_GAS = std::accumulate(gas.begin(), gas.end(), 0);
        const int SUM_COST = std::accumulate(cost.begin(), cost.end(), 0);
        if (SUM_COST > SUM_GAS) return -1;

        int total = 0;
        int idx = 0;
        for (int i = 0; i < cost.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            if (total < 0) {
                idx = i + 1;
                total = 0;
            }
        }

        return idx;
    }
};
