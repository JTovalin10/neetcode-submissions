class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr{};
        this->target = target;
        combSum(nums, curr);
        return res;
    }

private:
    vector<vector<int>> res{};
    int target;
    void combSum(const vector<int>& nums, vector<int>& curr, int curr_sum = 0, int idx = 0) {
        if (curr_sum > this->target) return;
        if (curr_sum == this->target) {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            int num = nums[i];
            curr.push_back(num);
            combSum(nums, curr, curr_sum + num, i);
            curr.pop_back();
        }
    }
};
