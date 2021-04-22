// Question Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* parents[501] = { NULL };
        vector<vector<TreeNode*>> nodesAtLevel(501);
        queue<TreeNode*> parentsQueue;
        // Find max depth, nodes at max depth and their parents
        TreeNode* onlyOneNode = findDeepestNodes(root, parents, nodesAtLevel, parentsQueue);
        if (onlyOneNode != NULL) {
            return onlyOneNode;
        }
        // Find the closest common parent of smallest subtree
        unordered_set<int> seen;
        while (!parentsQueue.empty()) {
            TreeNode* cur = parentsQueue.front();
            parentsQueue.pop();
            if (parentsQueue.empty()) {
                return cur;
            }
            if (seen.find(parents[cur->val]->val) == seen.end()) {
                parentsQueue.push(parents[cur->val]);
                seen.insert(parents[cur->val]->val);
            }
        }          
        return NULL;
    }
    
    // Finds max depth, nodes at max depth and their parents
    TreeNode* findDeepestNodes(TreeNode* root, TreeNode* parents[], vector<vector<TreeNode*>> &nodesAtLevel, queue<TreeNode*> &parentsQueue) {
        queue<TreeNode*> todo;
        todo.push(root);
        int maxDepth = 0;
        nodesAtLevel[maxDepth].push_back(root);
        while (!todo.empty()) {
            maxDepth++;
            for (int l = todo.size(); l > 0; l--) {
                TreeNode* cur = todo.front();
                todo.pop();
                if (cur->left) {
                    todo.push(cur->left);
                    nodesAtLevel[maxDepth].push_back(cur->left);
                    parents[cur->left->val] = cur;
                }
                if (cur->right) {
                    todo.push(cur->right);
                    nodesAtLevel[maxDepth].push_back(cur->right);
                    parents[cur->right->val] = cur;
                }
            }
        }
        // Check if we have only one node at max depth
        if (nodesAtLevel[maxDepth - 1].size() == 1) {
            return nodesAtLevel[maxDepth - 1].back();
        }
        // Push all nodes at max depth to queue for later processing
        unordered_set<int> seen;
        for (TreeNode* nodeAtMaxDepth : nodesAtLevel[maxDepth - 1]) {
            if (seen.find(parents[nodeAtMaxDepth->val]->val) == seen.end()) {
                parentsQueue.push(parents[nodeAtMaxDepth->val]);
                seen.insert(parents[nodeAtMaxDepth->val]->val);
            }
        }
        return NULL;
    }
};