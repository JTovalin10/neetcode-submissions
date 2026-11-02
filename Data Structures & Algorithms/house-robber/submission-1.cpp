class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        vector<int> houses(N + 1, 0);
        houses[1] = nums[0]; // the first house we rob is the 0th house
        for (int i = 2; i <= N; i++) {
            houses[i] = std::max(
                houses[i - 1], // skip the current house
                houses[i - 2] + nums[i - 1] // rob the current house
            );
        }
        return houses[N];
    }
};
