// Question Link 1: https://leetcode.com/problems/binary-tree-postorder-traversal/

// Iterative Solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        while (!nodeStack.empty()) {
            TreeNode* cur = nodeStack.top();
            nodeStack.pop();
            result.push_back(cur->val);
            if (cur->right) {
                nodeStack.push(cur->right);
            }
            if (cur->left) {
                nodeStack.push(cur->left);
            }
        }
        return result;
    }
};

// Recursive Solution
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
