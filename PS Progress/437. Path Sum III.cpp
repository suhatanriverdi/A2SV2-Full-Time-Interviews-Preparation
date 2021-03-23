// Question Link: https://leetcode.com/problems/path-sum-iii

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int result = 0;
        dfs(root, sum, result);
        return result;
    }
    
    void dfs(TreeNode* cur, int &sum, int &result) {
        if (cur == NULL) {
            return;
        }
        // Get path sums for curren node
        getPathSums(cur, 0, sum, result);
        dfs(cur->left, sum, result);
        dfs(cur->right, sum, result);
    }
    
    void getPathSums(TreeNode* cur, int curSum, int &sum, int &result) {
        if (cur == NULL) {
            return;
        }
        curSum += cur->val;
        if (curSum == sum) {
            result++;
        }
        getPathSums(cur->left, curSum, sum, result);
        getPathSums(cur->right, curSum, sum, result);
    }
};
