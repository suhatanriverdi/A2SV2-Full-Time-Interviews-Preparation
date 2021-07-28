// Question Link: https://leetcode.com/problems/construct-string-from-binary-tree

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
    string tree2str(TreeNode* cur) {
        if (cur == nullptr) {
            return "";
        }
        
        // Leaf
        if (cur->left == nullptr && cur->right == nullptr) {
            return to_string(cur->val);
        }
        
        // Not leaf
        string l = "";
        if (cur->left == nullptr) {
            l = "()";
        }
        else {
            l = "(" + tree2str(cur->left) + ")";
        }
        
        string r = "";
        if (cur->right != nullptr) {
            r = "(" + tree2str(cur->right) + ")";
        }
        
        return to_string(cur->val) + l + r;
    }
};