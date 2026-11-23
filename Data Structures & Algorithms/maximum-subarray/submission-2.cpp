class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int curr = 0;
        for (int num : nums) {
            curr = std::max(curr + num, num);
            res = std::max(res, curr);
        }
        return res;
    }
};
