class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        // find the min as that will tell us the offset
        while (l < r) {
            int m = l + (r - l) / 2;
            int num = nums[m];

            if (num > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        // l will be in the place of the smallest index
        int res1 = binary_search(nums, target, 0, l - 1);
        int res2 = binary_search(nums, target, l, nums.size() - 1);
        if (res1 != -1) return res1;
        if (res2 != -1) return res2;
        return -1;
    }

 private:

    int binary_search(const vector<int>& nums, int target, int l, int r) {
        if (l > r) return -1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            int num = nums[m];

            if (num == target) return m;

            if (num < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }
};