class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // num -> index
        unordered_map<int, int> memo{};
        memo.reserve(nums.size());

        for (int i{}; i < nums.size(); i++) {
            int num = nums[i];
            int diff = target - num;
            if (memo.count(diff)) {
                return {memo[diff], i};
            }
            memo[num] = i;
        }
        return {};
    }
};
