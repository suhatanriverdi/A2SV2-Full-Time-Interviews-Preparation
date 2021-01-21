// Question Link 1: https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
    
    void helper(TreeNode* cur, vector<int> &result) {
        if (cur == NULL) {
            return;
        }
        helper(cur->left, result);
        helper(cur->right, result);
        result.push_back(cur->val);
    }
};
