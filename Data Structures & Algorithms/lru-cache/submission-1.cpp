class ListNode {
public:
    ListNode() : key(-1), val(-1), next(nullptr), prev(nullptr) {}

    ListNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
    int key; // allows for fast-lookup to delete
    int val;
    ListNode* next;
    ListNode* prev;
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;

        lru.reserve(capacity);
    }
    
    int get(int key) {
        // the key doesnt exist
        if (!lru.count(key)) return -1;
         
        ListNode* value = lru.at(key);
        move_to_front(value);
        return value->val;
    }
    
    void put(int key, int value) {
        if (lru.count(key)) {
            ListNode* node = lru.at(key);
            node->val = value;
            move_to_front(node);
            return;
        }

        // need to amke the node so we can hand it to the lru
        if (lru.size() == capacity) {
            eject();
        }
        ListNode* new_node = new ListNode(key, value);
        // just add it to the front
        ListNode* old_front = head->next;
        new_node->next = old_front;
        old_front->prev = new_node;

        new_node->prev = head;
        head->next = new_node;
        lru[key] = new_node;
    }

private:
    int capacity;
    ListNode* head;
    ListNode* tail;
    unordered_map<int, ListNode*> lru{};

    void eject() {
        // grab the tail as that is the LRU
        ListNode* last_node = tail->prev;
        // now we can grab the previous one so we can unlink it
        ListNode* new_tail = last_node->prev;
        new_tail->next = tail;
        tail->prev = new_tail;

        // now we can remove this last_node
        lru.erase(last_node->key);
        delete last_node;
    }

    void move_to_front(ListNode*& node) {
        // grab its previous and front
        ListNode* prev = node->prev;
        ListNode* next = node->next;

        // make them together
        prev->next = next;
        next->prev = prev;

        // now add the node to the front
        ListNode* old_front = head->next;
        old_front->prev = node;
        head->next = node;

        // now link the node to the front
        node->next = old_front;
        node->prev = head;
    }
};
