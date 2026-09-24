class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen{};
        seen.reserve(nums.size());
        for (auto num : nums) {
            if (seen.contains(num)) return true;
            seen.insert(num);
        }
        return false;
    }
};