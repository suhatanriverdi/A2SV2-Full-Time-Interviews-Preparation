// Question Link: https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, int> counts;
        for (ListNode* &list : lists) {
            for (ListNode* walk = list; walk; walk = walk->next) {
                counts[walk->val]++;
            }
        }
        ListNode* root = new ListNode(-1);
        ListNode* walk = root;
        for (auto &it : counts) {
            while (it.second--) {
                walk->next = new ListNode(it.first);
                walk = walk->next;
            }
        }
        return root->next;
    }
};