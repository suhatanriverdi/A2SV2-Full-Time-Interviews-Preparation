// Question https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mini = min(p->val, q->val);
        int maxi = max(p->val, q->val);
        return helper(root, mini, maxi);
    }
    
    TreeNode* helper(TreeNode* cur, int mini, int maxi) {
        if (cur == NULL) {
            return NULL;
        }
        if (cur->val >= mini && cur->val <= maxi) {
            return cur;
        }
        else if (cur->val > maxi) {
            return helper(cur->left, mini, maxi);
        }
        return helper(cur->right, mini, maxi);
    }
};