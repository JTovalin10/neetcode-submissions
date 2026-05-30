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
        // base case
        if (r - l + 1 <= 1) return;

        // grab the pivot
        Pair pivot = pairs[r]; // right most
        // for std::Swap
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
        // move the pivot to the boundry between less than and greater oir equl seftion.
        pairs[r] = pairs[left];
        pairs[left] = pivot;
        helper(pairs, l, left - 1); // left
        helper(pairs, left + 1, r); // right
    }
};
