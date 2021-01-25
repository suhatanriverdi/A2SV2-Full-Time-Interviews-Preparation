// Question Link: https://leetcode.com/problems/find-bottom-left-tree-value

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        vector<int> row;
        row.push_back(root->val);
        while (!Q.empty()) {
            row.clear();
            for (int l = Q.size(); l > 0; l--) {
                TreeNode* cur = Q.front();
                Q.pop();
                if (cur->left) {
                    Q.push(cur->left);
                    row.push_back(cur->left->val);
                }
                if (cur->right) {
                    Q.push(cur->right);
                    row.push_back(cur->right->val);
                }
            }
        }
        return row[0];
    }
};