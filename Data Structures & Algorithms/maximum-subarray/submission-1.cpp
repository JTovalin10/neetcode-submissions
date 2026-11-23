class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int curr = 0;
        for (int num : nums) {
            if (curr < 0) {
                curr = 0;
            }
            curr += num;
            res = std::max(res, curr);
        }
        return res;
    }
};
