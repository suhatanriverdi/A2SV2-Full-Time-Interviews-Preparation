// Question Link: https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If number of nodes <= 1
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // // Add new head to make swapping easier
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;
        head = newHead;
        ListNode* tmp;
        ListNode* walk = newHead;
        ListNode* prev = newHead->next;
        ListNode* next = newHead->next->next;
        while (next) {
            tmp = next->next;
            walk->next = next;
            next->next = prev;
            prev->next = tmp;
            // Update walk
            walk = ((walk->next && walk->next->next) ? walk->next->next : NULL);
            // Update prev
            prev = ((walk && walk->next) ? walk->next : NULL);
            // Update next
            next = ((walk && walk->next && walk->next->next) ? walk->next->next : NULL);
        }
        return head->next;
    }
};