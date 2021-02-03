// Question Link: https://leetcode.com/problems/merge-k-sorted-lists/

// Min Heap Solution
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;
        for (ListNode* &head : lists) {
            if (head) {
                minHeap.push({head->val, head});
            }
        }
        ListNode* root = new ListNode();
        ListNode* walk = root;
        while (!minHeap.empty()) {
            // Get the minimum element from the heap
            pair<int, ListNode*> cur = minHeap.top();
            minHeap.pop();
            
            // Add the minimum element to the result
            walk->next = new ListNode(cur.second->val);
            walk = walk->next;
            
            // Update the pointer and push it back to minHeap
            if (cur.second->next) {
                minHeap.push({cur.second->next->val, cur.second->next});
            }
        }
        return root->next;
    }
};

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
