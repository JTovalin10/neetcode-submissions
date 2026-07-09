class Solution {
public:
    bool isPalindrome(string s) {
        const auto N = s.size();
        if (N < 1) return true;
        auto l{0uz}, r{N - 1};

        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;
        
            if (l < r && tolower(s[l]) != tolower(s[r])) return false;
            if (l < r) {
                l++;
                r--;
            }
        }
        return true;
    }

};
