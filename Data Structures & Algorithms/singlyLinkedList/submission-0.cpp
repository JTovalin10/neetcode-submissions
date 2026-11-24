class Node {
public:
    Node* next;
    int val;

    Node() : next(nullptr), val(-1) {}
    Node(int val) : next(nullptr), val(val) {}
};

class LinkedList {
public:
    LinkedList() {
        head = new Node();
        tail = head;
    }

    int get(int index) {
        Node* tmp = head->next;
        int idx = 0;
        while (tmp && idx < index) {
            tmp = tmp->next;
            idx++;
        }

        return (idx == index && tmp) ? tmp->val : -1;
    }

    void insertHead(int val) {
        Node* old_head = head->next;

        Node* new_head = new Node(val);
        head->next = new_head;
        new_head->next = old_head;
        // if the list was empty
        if (new_head->next == nullptr) {
            tail = new_head;
        }
    }
    
    void insertTail(int val) {
        // find the end first
        tail->next = new Node(val);
        tail = tail->next;
    }

    bool remove(int index) {
        Node* tmp = head;
        int idx = 0;

        while (tmp && idx < index) {
            tmp = tmp->next;
            idx++;
        }
        if (tmp && tmp->next) {
            if (tmp->next == tail) tail = tmp;
            Node* toDelete = tmp->next;
            tmp->next = toDelete->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> res{};
        Node* tmp = head->next;
        while (tmp) {
            res.push_back(tmp->val);
            tmp = tmp->next;
        }
        return res;
    }

private:
    Node* head{};
    Node* tail{};
};
