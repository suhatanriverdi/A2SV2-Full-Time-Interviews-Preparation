// Question Link: https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* walk1 = l1;
        ListNode* walk2 = l2;
        ListNode* result = NULL;
        ListNode* tail = result;
        int val1, val2, curMin;
        if (walk1 == NULL || walk2 == NULL) {
            return (walk1 == NULL ? walk2 : walk1);
        }
        while (walk1 || walk2) {
            val1 = (!walk1 ? -101 : walk1->val);
            val2 = (!walk2 ? -101 : walk2->val);
            curMin = min(val1, val2);
            if (result == NULL) {
                result = new ListNode(curMin);
                tail = result;
            } else {
                if (val1 == -101 && val2 == -101) {
                    break;
                }
                else if (val1 == -101) {
                    tail->next = new ListNode(val2);
                    tail = tail->next;
                    curMin = val2;
                }
                else if (val2 == -101) {
                    tail->next = new ListNode(val1);
                    tail = tail->next;
                    curMin = val1;
                }
                else if (val1 != -101 && val2 != -101) {
                    tail->next = new ListNode(curMin);
                    tail = tail->next;
                }
            }
            if (val1 == val2) {
                tail->next = new ListNode(curMin);
                tail = tail->next;
            }
            if (walk1 && curMin == walk1->val) {
                walk1 = (walk1 ? walk1->next : NULL);
            }
            if (walk2 && curMin == walk2->val) {
                walk2 = (walk2 ? walk2->next : NULL);
            }
        }
        return result;
    }
};