// Question Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzags;
        if (root == NULL) {
            return zigzags;
        }
        queue<TreeNode*> todo;
        todo.push(root);
        bool isReverse = false;
        while (!todo.empty()) {
            vector<int> tmp;
            for (int size = todo.size(); size > 0; size--) {
                TreeNode *cur = todo.front();
                tmp.push_back(cur->val);
                todo.pop();
                if (cur->left) {
                    todo.push(cur->left);
                }
                if (cur->right) {
                    todo.push(cur->right);
                }
            }
            if (isReverse) {
                reverse(begin(tmp), end(tmp));
            }
            isReverse = !isReverse;
            zigzags.push_back(tmp);
        }
        return zigzags;
    }
};
