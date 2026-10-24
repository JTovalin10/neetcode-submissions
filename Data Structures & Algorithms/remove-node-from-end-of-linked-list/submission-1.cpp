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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        // how many movements until the end
        int moves = length - n;
        if (moves == 0) {
            head = head->next;
            return head;
        } else {
            ListNode* prev = nullptr;
            curr = head;
            while (curr) {
                if (moves == 0) {
                    prev->next = curr->next;
                    break;
                }
                moves--;
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
