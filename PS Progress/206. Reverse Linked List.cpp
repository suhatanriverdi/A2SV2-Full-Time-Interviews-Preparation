// Question Link: https://leetcode.com/problems/reverse-linked-list/submissions/

// Iterative Using Extra Memory(Vector)
ListNode* reverseList(ListNode* head) {
    ListNode* walk = head;
    vector<int> temp;
    while (walk) {
        temp.push_back(walk->val);
        walk = walk->next;
    }
    walk = head;
    for (int i = temp.size() - 1; i >= 0; i--, walk = walk->next) {
        walk->val = temp[i];
    }
    return head;
}

// Recursive Using Extra Memory(Queue)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        queue<int> tmp;
        helper(head, tmp);
        return head;
    }
    
    void helper(ListNode* cur, queue<int> &tmp) {
        if (cur == NULL) {
            return;
        }
        tmp.push(cur->val);
        helper(cur->next, tmp);
        cur->val = tmp.front();
        tmp.pop();
    }
};

// Iterative In-Place 
class Solution {
public:
    // In-Place Iterative
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
};

// Recursive In-Place 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return helper(head, NULL);
    }
    
    ListNode* helper(ListNode* cur, ListNode* newHead) {
        if (cur == NULL) {
            return newHead;
        }
        ListNode* next = cur->next; // Save next
        cur->next = newHead;
        return helper(next, cur);
    }
};
