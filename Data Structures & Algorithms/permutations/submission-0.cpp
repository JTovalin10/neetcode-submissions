class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr{};
        vector<bool> used(nums.size(), false);
        perm(nums, curr, used); 
        return res;
    }

private:
    vector<vector<int>> res{};

    void perm(const vector<int>& nums, vector<int>& curr, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            curr.push_back(nums[i]);
            used[i] = true;
            perm(nums, curr, used);
            used[i] = false;
            curr.pop_back();
        }
    }
};
