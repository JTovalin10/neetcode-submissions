class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sums{};
        sums.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int res = target - num;
            if (sums.contains(res)) {
                return {sums[res], i};
            }
            sums[num] = i;
        }
        return {};
    }
};
