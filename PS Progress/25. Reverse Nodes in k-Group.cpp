// Question Link: https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        // Get the length of the list
        int length = 0, times;
        for (ListNode* walk = head; walk; walk = walk->next, length++) {};
        times = length / k;
        if (length == k) {
            return reverse(head, k)[0];
        }
        ListNode* newHead = new ListNode(-1);
        ListNode* appendPoint = newHead;
        vector<ListNode*> nodes; // reversedHead, reversedTail, nodeToContinue
        while (times--) {
            nodes = reverse(head, k);
            appendPoint->next = nodes[0];
            appendPoint = nodes[1];
            head = nodes[2];
        }
        appendPoint->next = head;
        return newHead->next;
    }
    
    // This should return "newHead", "tail" and "nodeToContinue" of the reversed list
    vector<ListNode*> reverse(ListNode* head, int k) {
        ListNode* reversedHead = NULL;
        ListNode* reversedTail = head;
        ListNode* temp = NULL;
        while (head && k--) {
            temp = head->next;
            head->next = reversedHead;
            reversedHead = head;
            head = temp;
        }
        return {reversedHead, reversedTail, head};
    }
};