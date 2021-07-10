// Question Link: https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> todo;
        todo.push({ root, 1 });
        int result = 1;
        while (!todo.empty()) {
            int start = todo.front().second;
            int end = todo.back().second;
            result = max(result, end - start + 1);
            for (int t = todo.size(); t > 0; t--) {
                pair<TreeNode*, int> cur = todo.front();
                todo.pop();
                if (cur.first->left) {
                    todo.push({ cur.first->left, ((cur.second - start) * 2) - 1 });
                }
                if (cur.first->right) {
                    todo.push({ cur.first->right, (cur.second - start) * 2 });
                }
            }
        }
        return result;
    }
};