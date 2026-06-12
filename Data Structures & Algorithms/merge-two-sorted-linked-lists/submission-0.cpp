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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        ListNode* tmp1 = list1;
        ListNode* tmp2 = list2;
        while (tmp1 && tmp2) {
            if (tmp1->val <= tmp2->val) {
                curr->next = tmp1;
                tmp1 = tmp1->next;
            } else {
                curr->next = tmp2;
                tmp2 = tmp2->next;
            }
            curr = curr->next;
        }

        while (tmp1) {
            curr->next = tmp1;
            curr = curr->next;
            tmp1 = tmp1->next;
        }

        while (tmp2) {
            curr->next = tmp2;
            curr = curr->next;
            tmp2 = tmp2->next;
        }
        return dummy->next;
    }
};
