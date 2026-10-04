class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res{};
        const int N = nums.size();
        for (int i = 0; i < N; i++) {
            // what is this edge case
            if (nums[i] > 0) break; // we can no longer get sum to 0
            if (i > 0 && nums[i] == nums[i - 1]) continue; // avoid duplicates

            // becomes 2 sum
            int l = i + 1, r = N - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    // push them forward
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                } else {
                    if (sum < 0) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return res;
    }
};
