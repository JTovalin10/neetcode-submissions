class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp{};
        backtrack(nums, tmp, 0);
        return res;
    }
private:
    vector<vector<int>> res{};

    void backtrack(const vector<int>& nums, vector<int>& tmp, int idx) {
        if (idx > nums.size()) return;
        res.push_back(tmp);
        for (int i{idx}; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtrack(nums, tmp, i + 1);
            tmp.pop_back();
        }
    }
};
