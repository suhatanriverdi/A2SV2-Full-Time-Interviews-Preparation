// Question Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        if (root == NULL) {
            return averages;
        }
        queue<TreeNode*> todo;
        todo.push(root);
        int numOfElements = 0;
        while (!todo.empty()) {
            double avg = 0.0;
            numOfElements = todo.size();
            for (int size = todo.size(); size > 0; size--) {
                TreeNode *cur = todo.front();
                avg += cur->val;
                todo.pop();
                if (cur->left) {
                    todo.push(cur->left);
                }
                if (cur->right) {
                    todo.push(cur->right);
                }
            }
            averages.push_back(avg / numOfElements);
        }
        return averages;
    }
};
