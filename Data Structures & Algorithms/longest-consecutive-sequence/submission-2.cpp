class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // populate the hash set
        unordered_set<int> seen(nums.begin(), nums.end());

        // loop through the nums
        int res = 0;
        for (int num : seen) {
            // start at beginning of seq
            if (!seen.count(num - 1)) {
                int cur = 1;
                while (seen.count(num + 1)) {
                    cur++;
                    num++;
                }
                res = max(res, cur);
            }
        }
        return res;
    }
};
