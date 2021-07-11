// Question Link: https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> result;
        // Iterative Pre-Order Traversal
        stack<TreeNode*> stack;
        stack.push(root);
        int voIndex = 0;
        while (!stack.empty()) {
            TreeNode* cur = stack.top();
            stack.pop();
            
            if (voyage[voIndex] != cur->val) {
                return {-1};
            }
            
            // The next node in the pre-order will be the left node if left does exists
            // else, it will be the right node, if the values does not match, we have only one thing to do which is flipping
            if (cur->left && cur->left->val != voyage[voIndex + 1]) {
                TreeNode* tmp = cur->right;
                cur->right = cur->left;
                cur->left = tmp;
                result.push_back(cur->val);
            }
            
            // Since stack is LIFO (First in last out)
            // We want right child to be processed last, if we push it first, it will be popped out lastly
            if (cur->right) {
                stack.push(cur->right);
            }
            // We want left child to be processed first
            if (cur->left) {
                stack.push(cur->left);
            }
            
            // Update voyage index
            voIndex++;
        }
        
        return result;
    }
};