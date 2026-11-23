class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int gas = nums[0];
        if (gas == 0) return false;
        for (int i = 1; i < nums.size() - 1; i++) {
            gas--;
            gas = std::max(gas, nums[i]);
            if (gas <= 0) return false;
        }
        return true;
    }
};
