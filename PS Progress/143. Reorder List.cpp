// Question Link: https://leetcode.com/problems/reorder-list

class Solution {
public:
    void reorderList(ListNode* head) {
        deque<ListNode*> nodesDeck;
        ListNode* w = head;
        while (w) {
            nodesDeck.push_back(w);
            w = w->next;
            nodesDeck.back()->next = NULL;
        }
        ListNode* newHead = new ListNode(-1); // Dummy Node
        ListNode* walk = newHead;
        while (!nodesDeck.empty()) {
            walk->next = nodesDeck.front();
            nodesDeck.pop_front();
            walk = walk->next;
            if (!nodesDeck.empty()) {
                walk->next = nodesDeck.back();
                nodesDeck.pop_back();
                walk = walk->next;
            }
        }
        head = newHead->next;
    }
};