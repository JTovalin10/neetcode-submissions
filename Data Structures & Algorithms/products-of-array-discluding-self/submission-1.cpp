class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) return nums;
        auto N = nums.size();
        vector<int> res(N, 1);
        int left = 1;
        for (int i = 0; i < N; i++) {
            res[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for (int i = N - 1; i >= 0; i--) {
            res[i] *= right;
            right *= nums[i];

        }
        return res;
    }
};

