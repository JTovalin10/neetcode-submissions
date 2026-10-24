/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        ListNode* l1c = l1;
        ListNode* l2c = l2;
        int carry = 0;
        while (l1c || l2c || carry > 0) {
            int val = carry;
            if (l1c) {
                val += l1c->val;
                l1c = l1c->next;
            }
            if (l2c) {
                val += l2c->val;
                l2c = l2c->next;
            }
            carry = val / 10;
            val = val % 10;

            ListNode* new_node = new ListNode(val);
            curr->next = new_node;
            curr = curr->next;
        }
        return dummy->next;
    }

private:
};
