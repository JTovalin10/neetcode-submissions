class TimeMap {
public:
    TimeMap() = default;
    
    void set(string key, string value, int timestamp) {
        kv[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (kv.find(key) == kv.end()) return "";

        const vector<pair<string, int>>& values = kv[key];
        if (values.empty()) return "";
        
        int l = 0, r = values.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (values[m].second == timestamp) return values[m].first;

            if (values[m].second < timestamp) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return r >= 0 ? values[r].first : "";
    }

private:
// key : { value : timestamp }
unordered_map<string, vector<pair<string, int>>> kv{};
};
