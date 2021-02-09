// Question Link: https://leetcode.com/problems/binary-tree-right-side-view

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result, tmp;
        if (root == NULL) {
            return result;
        }
        queue<TreeNode*> todo;
        todo.push(root);
        result.push_back(root->val);
        while (!todo.empty()) {
            for (int t = todo.size(); t > 0; t--) {
                TreeNode* cur = todo.front();
                todo.pop();
                if (cur->left) {
                    todo.push(cur->left);
                    tmp.push_back(cur->left->val);
                }
                if (cur->right) {
                    todo.push(cur->right);
                    tmp.push_back(cur->right->val);
                }
            }
            if (!tmp.empty()) {
                result.push_back(tmp.back());
            }
            tmp.clear();
        }
        return result;
    }
};