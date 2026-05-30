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
       helper(pairs, 0, (int)pairs.size() - 1);
       return pairs;
    }

    void helper(vector<Pair>& pairs, int l, int r) {
        if (r - l + 1 <= 1) return;

        Pair pivot = pairs[r]; // right most
        int left = l;

        // parititon
        for (int i = l; i < r; i++) {
            if (pairs[i].key < pivot.key) {
                Pair tmp = pairs[left];
                pairs[left] = pairs[i];
                pairs[i] = tmp;
                left++;
            }
        }
        pairs[r] = pairs[left];
        pairs[left] = pivot;
        helper(pairs, l, left - 1); // left
        helper(pairs, left + 1, r); // right
    }
};
