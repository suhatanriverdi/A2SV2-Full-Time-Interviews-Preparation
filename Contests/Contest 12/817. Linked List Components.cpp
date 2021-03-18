// Question Link: https://leetcode.com/problems/linked-list-components/

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int, int> valPlaceMap; // {value, place in L}
        vector<int> L;
        for (; head; head = head->next) {
            L.push_back(head->val);
        }
        // Find values and places/indices
        for (int i = 0; i < L.size(); i++) {
            valPlaceMap[L[i]] = i;
        }
        // Mark all values
        for (int i = 0; i < G.size(); i++) {
            L[valPlaceMap[G[i]]] = -1;
        } 
        // Count num of islands
        int result = 0;
        for (int i = 0; i < L.size(); i++) {
            int start = i;
            if (L[start] == -1) {
                result++;
                while (start < L.size() && L[start] == -1) {
                    start++;
                }
            }
            i = start;
        }
        return result;
    }
};
