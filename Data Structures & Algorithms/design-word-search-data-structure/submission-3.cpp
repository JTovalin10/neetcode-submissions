class TrieNode {
public:
    unordered_map<char, TrieNode*> node;
    bool end;
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

    bool find(const string& word) {
        TrieNode* tmp = root;
        return dfs(tmp, word, 0);
    }

private:
    TrieNode* root;

    bool dfs(TrieNode* curr, const string& word, int idx) {
        if (idx == word.size()) return curr->end;
        for (int i = idx; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (const auto& [_, ptr] : curr->node) {
                    if (dfs(ptr, word, i + 1)) return true;
                }
                return false;
            } else {
                if (curr->node.find(c) == curr->node.end()) return false;
                curr = curr->node[c];
            }
        }
        return curr->end;
    }
};

class WordDictionary {
public:
    WordDictionary() = default;
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.find(word);
    }

private:
    Trie trie{};
};
