// Question Link: https://leetcode.com/problems/path-sum-ii

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }
    
    void dfs(TreeNode* node, int targetSum, vector<int> path, vector<vector<int>> &result) {
        if (!node) {
            return;
        }
        
        targetSum -= node->val;
        path.push_back(node->val);
        if (!node->left && !node->right && targetSum == 0) {
            result.push_back(path);
        }
        
        dfs(node->left, targetSum, path, result);
        dfs(node->right, targetSum, path, result);
    }
};