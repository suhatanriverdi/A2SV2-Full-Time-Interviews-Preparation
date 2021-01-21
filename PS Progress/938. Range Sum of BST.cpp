// Question Link: https://leetcode.com/problems/range-sum-of-bst/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int result = 0;
        traverse(root, low, high, result);
        return result;
    }
    
    void traverse(TreeNode* cur, int &l, int &h, int &result) {
        if (cur == NULL) {
            return;
        }
        if (cur->val >= l && cur->val <= h) {
            result += cur->val;
        }
        traverse(cur->left, l, h, result);
        traverse(cur->right, l, h, result);
    }
};