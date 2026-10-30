class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr{};
        backtrack(0, curr, nums);
        return res;
    }

private:
    vector<vector<int>> res{};

    void backtrack(int idx, vector<int>& curr, const vector<int>& nums) {
        res.push_back(curr);

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;

            curr.push_back(nums[i]);
            backtrack(i + 1, curr, nums);
            curr.pop_back();
        }
    }
};
