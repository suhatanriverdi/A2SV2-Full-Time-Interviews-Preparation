// Question Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int kthElement;
        helper(root, k, kthElement);
        return kthElement;
    }
    
    void helper(TreeNode* cur, int &k, int &kthElement) {
        if (cur == NULL) {
            return;
        }
        helper(cur->left, k, kthElement);
        k--;
        if (k == 0) {
            kthElement = cur->val;
            return;
        }
        helper(cur->right, k, kthElement);
    }
};
