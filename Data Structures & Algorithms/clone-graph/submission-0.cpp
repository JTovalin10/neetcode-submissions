/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        return clone(node);
    }

private:
    unordered_map<Node*, Node*> seen{};

    Node* clone(Node* node) {
        if (!node) return nullptr;
        if (seen.count(node)) return seen[node];
        Node* new_node = new Node(node->val);

        seen[node] = new_node;
        for (const auto& curr : node->neighbors) {
            new_node->neighbors.push_back(clone(curr));
        }
        return new_node;
    }
};
