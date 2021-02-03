// Question Link: https://leetcode.com/problems/merge-k-sorted-lists/

// Counting Sort Solution
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> counts(20001, 0);
        for (ListNode* &list : lists) {
            for (ListNode* walk = list; walk; walk = walk->next) {
                counts[walk->val + 10000]++;
            }
        }
        ListNode* root = new ListNode();
        ListNode* walk = root;
        for (int i = 0; i < counts.size(); i++) {
            while (counts[i]--) {
                walk->next = new ListNode(i - 10000);
                walk = walk->next;
            }
        }
        return root->next;
    }
};

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
