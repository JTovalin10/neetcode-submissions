/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodes{};
        //nodes[nullptr] = nullptr;
        Node* curr = head;
        while (curr) {
            nodes[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // now we can loop through our hashmap
        for (const auto& [old, deep] : nodes) {
            if (!old) continue;
            // grab old
            Node* deep_old = nodes[old->next];
            deep->next = deep_old;
            
            // grab random
            Node* old_random = old->random;
            if (old_random == nullptr) {
                deep->random = nullptr;
            } else {
                // grab it from the map
                Node* deep_random = nodes[old_random];
                deep->random = deep_random;
            }
        }
        return nodes[head];
    }
};
