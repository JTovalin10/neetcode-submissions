class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        const auto N = nums.size();
        vector<vector<int>> res{};
        for (int i{}; i < N; i++) {
            int n1 = nums[i];
            if (n1 > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = N - 1;
            while (l < r) {
                int n2 = nums[l];
                int n3 = nums[r];
                int sum = n1 + n2 + n3;
                if (sum == 0) {
                    res.push_back({n1, n2, n3});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                } else {
                    if (sum < 0) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};
