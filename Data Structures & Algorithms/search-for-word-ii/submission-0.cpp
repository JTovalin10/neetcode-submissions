class TrieNode {
public:
    unordered_map<char, TrieNode*> node{};
    bool end = false;
};

class Trie {
public:

    Trie() : root(new TrieNode()) {}

    void insert(const string& word) {
        TrieNode* tmp = root;
        for (char c : word) {
            if (tmp->node.find(c) == tmp->node.end()) {
                tmp->node[c] = new TrieNode();
            }
            tmp = tmp->node[c];
        }
        tmp->end = true;
    }

    bool prefix(const string& word) {
        TrieNode* tmp = root;
        for (char c : word) {
            if (tmp->node.find(c) == tmp->node.end()) {
                return false;
            }
            tmp = tmp->node[c];
        }
        return true;
    }

    bool contains(const string& word) {
        TrieNode* tmp = root;
        for (char c : word) {
            if (tmp->node.find(c) == tmp->node.end()) {
                return false;
            }
            tmp = tmp->node[c];
        }
        return tmp->end;
    }

    void remove(const string& word) {
        TrieNode* tmp = root;
        for (char c : word) {
            if (tmp->node.find(c) == tmp->node.end()) {
                return;
            }
            tmp = tmp->node[c];
        }
        tmp->end = false;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        res.reserve(words.size());
        for (const auto& word : words) {
            trie.insert(word);
        }

        // now find the words
        ROW = board.size();
        COL = board[0].size();
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                string word = "";
                dfs(i, j, board, words, word);
            }
        }
        res.shrink_to_fit();
        return res;
    }

private:
    int ROW;
    int COL;
    vector<string> res;
    Trie trie{};

    void dfs(int row, int col, vector<vector<char>>& board, vector<string>& words, string& word) {
        if (row < 0 || col < 0 || row >= ROW || col >= COL) return;
        if (board[row][col] == '.') return;

        char tmp = board[row][col];
        word += tmp;
        if (!trie.prefix(word)) {
            word.pop_back();
            return;
        }

        if (trie.contains(word)) {
            res.push_back(word);
            trie.remove(word);
        }
        
        board[row][col] = '.';


        dfs(row + 1, col, board, words, word);
        dfs(row - 1, col, board, words, word);
        dfs(row, col + 1, board, words, word);
        dfs(row, col - 1, board, words, word);
        
        word.pop_back();
        board[row][col] = tmp;
    }

};