class Solution {
public:
    int search(vector<int>& nums, int target) {
        // we want to first find the pivot
        int pivot = find_pivot(nums);
        
        int left_side = binary_search(nums, target, 0, pivot - 1);
        if (left_side != -1) return left_side;

        int right_side = binary_search(nums, target, pivot, (int)nums.size() - 1);
        if (right_side != -1) return right_side;

        return -1;
    }

private:
    int find_pivot(const vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        // we want to find the smallest element
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            int num = nums[mid];
            if (num < nums[right]) {
                // we want to keep exploring this as it is the smallest
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    int binary_search(const vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;    

            if (nums[mid] == target) return mid;

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
