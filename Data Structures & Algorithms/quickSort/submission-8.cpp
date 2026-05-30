// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> quickSort(vector<Pair>& pairs) {
        helper(pairs, 0, static_cast<int>(pairs.size() - 1));
        return pairs;
    }

    void helper(vector<Pair>& pairs, int start, int end) {
        if (end - start + 1 <= 1) return;

        Pair pivot = pairs[end];
        int left = start;
        for (int i{start}; i < end; i++) {
            if (pairs[i].key < pivot.key) {
                Pair tmp = pairs[i];
                pairs[i] = pairs[left];
                pairs[left] = tmp;
                left++;
            }
        }
        pairs[end] = pairs[left];
        pairs[left] = pivot; 
        helper(pairs, start, left - 1);
        helper(pairs, left + 1, end);
    }
};
