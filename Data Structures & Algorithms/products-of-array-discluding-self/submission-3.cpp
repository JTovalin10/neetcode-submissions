class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        const int N = nums.size();
        vector<int> res(N, 1);
        int num = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = num;
            num *= nums[i];
        }
        num = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= num;
            num *= nums[i];
        }
        return res;
    }
};
