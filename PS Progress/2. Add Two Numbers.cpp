// Question Link: https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* A = l1;
        ListNode* B = l2;
        ListNode* result = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while (A || B) {
            int sum = (A ? A->val : 0) + (B ? B->val : 0) + carry;
            carry = (sum >= 10 ? 1 : 0);
            if (result == NULL) {
                result = new ListNode(sum % 10);
                tail = result;
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            // Check the next beforehand, we cannot check NULL->next
            A = (A ? A->next : NULL);
            B = (B ? B->next : NULL);
        }
        // If we have carry
        if (carry) {
            tail->next = new ListNode(carry);
        }
        return result;
    }
};