// Question Link: https://leetcode.com/problems/range-sum-of-bst/

// Solution 2 (Better)
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
        // Check if no need to go left, if we are less than L
        if (cur->val < l) {
            return traverse(cur->right, l, h, result);
        }
        // Check if no need to go right, if we are higher than H
        if (cur->val > h) {
            return traverse(cur->left, l, h, result);
        }
        if (cur->val >= l && cur->val <= h) {
            result += cur->val;
        }
        traverse(cur->left, l, h, result);
        traverse(cur->right, l, h, result);
    }
};

// Solution 1
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
