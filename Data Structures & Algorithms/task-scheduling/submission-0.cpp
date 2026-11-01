class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        for (const char c : tasks) {
            counts[c - 'A']++;
        }

        priority_queue<int> max_heap{};
        for (const int cnt : counts) {
            if (cnt > 0) max_heap.push(cnt);
        }

        int time = 0;   
        // cnt, time
        queue<pair<int, int>> waiting_queue{};
        while (!max_heap.empty() || !waiting_queue.empty()) {
            time++;

            if (max_heap.empty()) {
                // fast forward to the next item
                time = waiting_queue.front().second;
            } else {
                int cnt = max_heap.top() - 1; max_heap.pop();
                // it must now wait n cycles
                if (cnt > 0) waiting_queue.push({cnt, time + n});
            }

            // if we fast forwarded to this or we have a waiting queue
            if (!waiting_queue.empty() && waiting_queue.front().second == time) {
                max_heap.push(waiting_queue.front().first);
                waiting_queue.pop();
            }
        }
        return time;
    }
};
