class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap(stones.begin(), stones.end());
        while (max_heap.size() > 1) {
            int num1 = max_heap.top(); max_heap.pop();
            int num2 = 0;
            if (!max_heap.empty()) {
                num2 = max_heap.top(); max_heap.pop();
            }
            if (num1 == num2) continue;
            max_heap.push(num1 - num2);
        }
        return max_heap.empty() ? 0 : max_heap.top();
    }
};
