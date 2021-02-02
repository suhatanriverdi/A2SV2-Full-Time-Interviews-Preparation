// Question Link: https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long int mi = LONG_MIN, ma = LONG_MAX;
        return BSThelper(root, mi, ma);
    }
    
    bool BSThelper(TreeNode* cur, long long int lowerBound, long long int upperBound) {
        if (cur == NULL) {
            return true;
        }
        bool isLeftBST = BSThelper(cur->left, lowerBound, cur->val);
        bool isRightBST = BSThelper(cur->right, cur->val, upperBound);
        if (isLeftBST && isRightBST &&
            (cur->left == NULL || (cur->left && cur->val > cur->left->val)) &&
            (cur->right == NULL || (cur->right && cur->val < cur->right->val)) &&
            (cur->val > lowerBound && cur->val < upperBound)) {
            return true;
        }
        return false;
    }
};