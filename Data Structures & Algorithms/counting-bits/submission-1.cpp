class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res{};
        n_to_bits.assign(n + 1, -1);
        for (int i = 0; i <= n; i++) {
            res.push_back(count_one(i));
        }
        return res;
    }

private:
    vector<int> n_to_bits{};
    const int BITS = 32;
    
    int count_one(int n) {
        int res = 0;
        int num = n;
        for (int i = 0; i < BITS; i++) {
            if (n_to_bits[num] != -1) {
                res += n_to_bits[num];
                break;
            }
            res += (num & 1);
            num = num >> 1;
        }
        n_to_bits[n] = res;
        return res;
    }
};
