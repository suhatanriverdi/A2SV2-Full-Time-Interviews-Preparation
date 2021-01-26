// Question Link: https://leetcode.com/problems/longest-univalue-path

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int longestUniPathLength = 0;
        traverse(root, longestUniPathLength);
        return longestUniPathLength;
    }
    
    // Keep going as long as we see same node values with val, and return max path length
    int keepGoing(TreeNode* cur, int &val) {
        if (cur == NULL || (cur && cur->val != val)) {
            return 0;
        }
        return 1 + max(keepGoing(cur->left, val), keepGoing(cur->right, val));
    }
    
    // Traverse each node and find max uni path
    void traverse(TreeNode* cur, int &maxPathLength) {
        if (cur == NULL) {
            return;
        }
        int pathSum = keepGoing(cur->left, cur->val) + keepGoing(cur->right, cur->val);
        maxPathLength = max(maxPathLength, pathSum);
        traverse(cur->left, maxPathLength);
        traverse(cur->right, maxPathLength);
    }
};