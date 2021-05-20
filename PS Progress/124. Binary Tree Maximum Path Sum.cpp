// Question Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = root->val;
        helper(root, maxPathSum);
        return maxPathSum;
    }
    
    int helper(TreeNode* cur, int &maxPathSum) {
        if (cur == NULL) {
            return -1001;
        }
        
        // The node value itself might be the greatest
        maxPathSum = max(maxPathSum, cur->val);
        
        // Leaf
        if (cur->left == NULL && cur->right == NULL) {
            return cur->val;
        }
        
        int LSum = helper(cur->left, maxPathSum);
        int RSum = helper(cur->right, maxPathSum);
        
        // Calculate the greatest sum seen so far
        maxPathSum = max(maxPathSum, max(cur->val + RSum + LSum, max(cur->val + RSum, max(cur->val, cur->val + LSum))));

        // Return Max of all path sum possibilities
        return max(cur->val + RSum, max(cur->val, cur->val + LSum));
    }
};