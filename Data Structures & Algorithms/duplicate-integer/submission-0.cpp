class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s{};
        s.reserve(nums.size());
        for (auto num : nums) {
            if (s.count(num)) return true;
            s.insert(num);
        }
        return false;
    }
};