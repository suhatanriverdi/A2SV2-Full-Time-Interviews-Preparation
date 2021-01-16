// Question Link: https://leetcode.com/problems/remove-linked-list-elements

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* tmp = head;
        head = new ListNode(-1);
        head->next = tmp;
        ListNode* walk = head;
        while (walk) {
            if (walk->next && walk->next->val == val) {
                walk->next = walk->next->next;
            } else {
                walk = walk->next;
            }
        }
        return head->next;
    }
};
