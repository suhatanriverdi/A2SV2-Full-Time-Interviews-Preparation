// Question Link: https://leetcode.com/problems/search-in-a-binary-search-tree

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;
        }
        if (val == root->val) {
            return root;
        }
        else if (val < root->val) {
            return searchBST(root->left, val);
        }
        return searchBST(root->right, val);
    }
};