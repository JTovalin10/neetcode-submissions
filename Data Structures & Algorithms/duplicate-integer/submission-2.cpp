class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        for (int r{1}; r < nums.size(); ++r) {
            if (nums[l] == nums[r]) return true;
            l++;
        }
        return false;
    }
};