// Question https://leetcode.com/problems/binary-tree-pruning

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* dummyRoot = new TreeNode(1453);
        dummyRoot->right = root;
        helper(dummyRoot);
        return dummyRoot->right;
    }
    
    bool helper(TreeNode* &cur) {
        if (cur == NULL) {
            return false;
        }
        
        bool hasOneL = helper(cur->left);
        bool hasOneR = helper(cur->right);
        
        cur->left = (hasOneL == false) ? NULL : cur->left;
        cur->right = (hasOneR == false) ? NULL : cur->right;
        
        return (cur->val == 1) || hasOneL || hasOneR;
    }
};