class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1, r = 1;
        int prev = nums[0];
        int found = 1;
        while (r < nums.size()) {
            int curr = nums[r];
            if (prev != curr) {
                // we found a unique element
                nums[l] = curr;
                found++;
                l++;
            }
            prev = curr;
            r++;
        }
        return found;
    }
};