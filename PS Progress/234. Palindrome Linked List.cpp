// Question Link: https://leetcode.com/problems/palindrome-linked-list/

// Solution 1
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* walk = head;
        int length = 0;
        // Get the length of the list
        while (walk) {
            length++;
            walk = walk->next;
        }
        ListNode* mid = findMiddle(head);
        ListNode* left = head;
        ListNode* right = mid;
        for (int i = 1, rIdx = (length / 2) + (length % 2); i <= length / 2 && left && right; i++) {
            // Update the right pointer to the correct position
            right = mid;
            int times = (rIdx) - i;
            while (right && times--) {
                right = right->next;
            }
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
        }
        return true;
    }
    
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast) {
            if (fast->next == NULL) {
                return slow;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Solution 2
class Solution {
ListNode* prev = NULL;
public:
    bool isPalindrome(ListNode* head) {
        prev = head;
        return helper(head);
    }
    
    bool helper(ListNode* head) {
        if (head == NULL) {
            return true;
        }
        bool res = helper(head->next);
        if (head->val != prev->val) {
            res = false;
        }
        prev = prev->next;
        return res;
    }
};
