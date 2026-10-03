class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() < 2) return true;
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !std::isalnum(s[l])) l++;
            while (l < r && !std::isalnum(s[r])) r--;
            char l1 = tolower(s[l]);
            char l2 = tolower(s[r]);
            if (l1 != l2) return false;
            l++;
            r--;
        }
        return true;
    }
};
