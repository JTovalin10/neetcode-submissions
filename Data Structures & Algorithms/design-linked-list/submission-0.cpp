struct Node {
    Node* next = nullptr;
    Node* prev = nullptr;
    int val;

    Node(int val = -1) : val(val) {}
};

class MyLinkedList {
private:
Node* head;
Node* tail;

public:
    MyLinkedList() {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;        
    }
    
    int get(int index) {
        int i = 0;
        Node* tmp = head->next;
        while (tmp != tail && i < index) {
            tmp = tmp->next;
            i++;
        }
        if (i == index && tmp != tail) return tmp->val;
        return -1; 
    }
    
    void addAtHead(int val) {
        Node* new_node = new Node(val);
        Node* old_head = head->next;

        new_node->next = old_head;
        new_node->prev = head;

        old_head->prev = new_node;
        head->next = new_node;
    }
    
    void addAtTail(int val) {
         Node* new_node = new Node(val);
        Node* old_tail = tail->prev;

        new_node->next = tail;
        new_node->prev = old_tail;

        old_tail->next = new_node;
        tail->prev = new_node;
    }
    
    void addAtIndex(int index, int val) {
        int i = 0;
        Node* tmp = head->next;
        while (tmp && i < index) {
            tmp = tmp->next;
            i++;
        }

        if (i == index && tmp) {
            Node* new_node = new Node(val);
            Node* p = tmp->prev;

            p->next = new_node;
            tmp->prev = new_node;

            new_node->next = tmp;
            new_node->prev = p;
        }
    }
    
    void deleteAtIndex(int index) {
        int i = 0;
        Node* tmp = head->next;
        while (tmp != tail && i < index) {
            tmp = tmp->next;
            i++;
        }

        if (i == index && tmp != tail) {
            Node* p = tmp->prev;
            Node* n = tmp->next;

            n->prev = p;
            p->next = n;
            delete tmp;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */