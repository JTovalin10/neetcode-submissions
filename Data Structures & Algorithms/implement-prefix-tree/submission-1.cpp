class TrieNode {
public:
    TrieNode() = default;
    unordered_map<char, TrieNode*> node{};
    bool end = false;
};

class Trie {
public:

    Trie() : root(new TrieNode()) {}

    void insert(const string& str) {
        TrieNode* tmp = root;
        for (char c : str) {
            if (tmp->node.find(c) == tmp->node.end()) {
                tmp->node[c] = new TrieNode();
            }
            tmp = tmp->node[c];
        }
        tmp->end = true;
    }

    bool contains(const string& str) {
        TrieNode* tmp = root;
        for (char c : str) {
            if (tmp->node.find(c) == tmp->node.end()) return false;
            tmp = tmp->node[c];
        }
        return tmp->end;
    }

    bool prefix(const string& str) {
        TrieNode* tmp = root;
        for (char c : str) {
            if (tmp->node.find(c) == tmp->node.end()) return false;
            tmp = tmp->node[c];
        }
        return true;
    }

private:
    TrieNode* root{};
};

class PrefixTree {
public:
    PrefixTree() = default;
    
    void insert(string& word) {
        trie.insert(word);
    }
    
    bool search(string& word) {
        return trie.contains(word);
    }
    
    bool startsWith(string& prefix) {
        return trie.prefix(prefix);
    }

private:
    Trie trie{};
};
