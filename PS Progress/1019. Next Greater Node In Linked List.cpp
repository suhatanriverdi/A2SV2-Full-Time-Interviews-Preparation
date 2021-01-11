// Question Link: https://leetcode.com/problems/next-greater-node-in-linked-list/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        stack<int> idxStack; // Monothon Decreasing
        for (; head; head = head->next) {
            result.push_back(head->val);
        }
        for (int i = 0; i < result.size(); i++) {
            while (!idxStack.empty() && result[idxStack.top()] < result[i]) {
                result[idxStack.top()] = result[i];
                idxStack.pop();
            }
            idxStack.push(i);
        }
        for (; !idxStack.empty(); idxStack.pop()) {
            result[idxStack.top()] = 0;
        }
        return result;
    }
};
