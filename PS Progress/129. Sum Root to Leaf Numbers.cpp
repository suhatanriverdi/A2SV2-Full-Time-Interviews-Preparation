// Question Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        string s = "";
        return dfs(root, s);
    }
    
    int dfs(TreeNode* cur, string s) {
        if (cur == NULL) {
            return 0;
        }
        s += cur->val + '0';
        if (!cur->left && !cur->right) {
            return stoi(s);
        }
        return dfs(cur->left, s) + dfs(cur->right, s);
    }
};