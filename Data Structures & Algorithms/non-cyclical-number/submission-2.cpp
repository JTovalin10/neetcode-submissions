class Solution {
public:
    bool isHappy(int n) {
        return find(n);
    }

private:
    unordered_set<int> seen{};

    bool find(int n) {
        if (n == 1) return true;
        if (seen.count(n)) return false;
        seen.insert(n);
        
        int sum = 0;
        while (n > 0) {
            int num = n % 10;

            sum += std::pow(num, 2);
            n /= 10;
        }

        return find(sum);
    }
};
