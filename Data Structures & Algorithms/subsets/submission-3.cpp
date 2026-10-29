class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        backtrack(nums, tmp, 0);
        return res;
    }

private:
    vector<vector<int>> res{};

    void backtrack(const vector<int>& nums, vector<int>& curr, int idx) {
        if (idx == nums.size()) {
            res.push_back(curr);
            return;
        }
        res.push_back(curr);

        for (int i = idx; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(nums, curr, i + 1);
            curr.pop_back();
        }
    }

};
