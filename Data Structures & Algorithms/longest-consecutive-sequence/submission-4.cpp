class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int res{0};
        for (int num : seen) {
            // the first number in a sequence
            if (!seen.count(num - 1)) {
                int curr{1};
                while (seen.count(num + 1)) {
                    num++;
                    curr++;
                }
                res = max(res, curr);
            }
        }
        return res;
    }
};
