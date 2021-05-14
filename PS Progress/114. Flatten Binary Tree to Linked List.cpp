// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        vector<int> LList;
        dfs(root, LList);
        root->left = NULL;
        root->right = NULL;
        TreeNode* walk = root;
        for (int i = 1; i < LList.size(); i++) {
            walk->left = NULL;
            walk->right = new TreeNode(LList[i]);
            walk = (walk ? walk->right : NULL);
        }
    }
    
    void dfs(TreeNode* cur, vector<int> &LList) {
        if (cur == NULL) {
            return;
        }
        LList.push_back(cur->val);
        dfs(cur->left, LList);
        dfs(cur->right, LList);
    }
};