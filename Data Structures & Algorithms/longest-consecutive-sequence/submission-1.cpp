class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> n_set(nums.begin(), nums.end());

        int lc_seq{0};
        for (int num : nums) {
            if (!n_set.count(num + 1)) {
                int cnt{1};
                int cur = num;
                while (n_set.count(cur - 1)) {
                    cur--;
                    cnt++;
                }
                lc_seq = max(lc_seq, cnt);
            }
        }
        return lc_seq;
    }
};
