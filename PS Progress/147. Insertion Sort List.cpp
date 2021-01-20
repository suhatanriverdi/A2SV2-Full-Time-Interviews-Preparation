// Question Link: https://leetcode.com/problems/insertion-sort-list

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // Insert dummy node to make future insertions easier
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;
        ListNode* walk = head->next;
        ListNode* tail = head;
        while (walk) {
            bool inserted = false;
            // Find correct slot for current node and place it if possible
            ListNode* nodeToInsert = walk;
            ListNode* cur = head;
            for (; cur->next && cur != nodeToInsert; cur = cur->next) {
                // Location found, inserts node here
                if (nodeToInsert->val < cur->next->val) {
                    ListNode* tmp = cur->next;
                    ListNode* beInserted = new ListNode(nodeToInsert->val);
                    cur->next = beInserted;
                    beInserted->next = tmp;
                    inserted = true;
                    break;
                }
            }
            if (inserted == true) {
                // If removed node is at tail 
                if (walk->next == NULL) {
                    tail->next = NULL;
                    break;
                }
                // Remove current node since it is already inserted
                else {
                    walk->val = (walk->next ? walk->next->val : NULL);
                    walk->next = (walk->next && walk->next->next ? walk->next->next : NULL);
                }
            } 
            else {
                walk = walk->next;
                tail = tail->next;
            }
        }
        return head->next;
    }
};