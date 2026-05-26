class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, {}, nums);
        return res;
    }
private:
vector<vector<int>> res{};

void dfs(int n, vector<int> curr, const vector<int>& nums) {
    if (n >= nums.size()) {
        res.push_back(curr);
        return;
    }
    
    dfs(n + 1, curr, nums);
    curr.push_back(nums[n]);
    dfs(n + 1, curr, nums);
    curr.pop_back();
}
};
