class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> bucket(3);
        for (int num : nums) {
            bucket[num]++;
        }
        int index = 0;
        for (int i = 0; i < bucket.size(); i++) {
            while (bucket[i] > 0) {
                bucket[i]--;
                nums[index] = i;
                index++;
            }
        }
    }
};