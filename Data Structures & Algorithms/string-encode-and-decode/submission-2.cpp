class Solution {
public:

    string encode(vector<string>& strs) {
        // length of str + # + str
        string res;
        for (const auto& str : strs) {
            int size = str.size();
            res += to_string(size) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0; // first offset (will be placed at each length)
        vector<string> res{};
        while (i < s.size()) {
            auto hash = s.find("#", i); // finds the first instance of s
            // (hash - i) will give us where the size starts
            string size_str = s.substr(i, hash - i);
            int size = stoi(size_str);
            string word = s.substr(hash + 1, size);
            res.push_back(word);
            // num + # + word, example: 3#abc
            i += size_str.size() + 1 + size;
        }
        return res;
    }
};
