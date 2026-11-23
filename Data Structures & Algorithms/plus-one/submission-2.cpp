class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            // add the carry
            int num = digits[i];
            num += carry;

            // update the carry and reduce the num
            carry = num / 10;
            num %= 10;

            // insert the number
            digits[i] = num;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
