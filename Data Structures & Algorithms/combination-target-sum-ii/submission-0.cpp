class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr{};
        this->target = target;
        std::sort(candidates.begin(), candidates.end());
        find(candidates, curr);
        return res;
    }

private:
    vector<vector<int>> res{};
    int target{};
    
    void find(const vector<int>& cand, vector<int>& curr, int curr_sum = 0, int idx = 0) {
        // we are out of bounds
        if (curr_sum > this->target) return;
        if (curr_sum == this->target) {
            res.push_back(curr);
            return;
        }
        if (idx >= cand.size()) return;

        for (int i = idx; i < cand.size(); i++) {
            int num = cand[i];
            if (i > idx && num == cand[i - 1]) continue;
            curr.push_back(num);
            find(cand, curr, curr_sum + num, i + 1);
            curr.pop_back();
        }
    }
};
