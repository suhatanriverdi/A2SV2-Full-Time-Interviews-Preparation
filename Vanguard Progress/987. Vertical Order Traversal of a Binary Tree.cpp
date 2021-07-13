// Question https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<vector<int>, vector<int>> nodesMap;
        int maxC = 0, minC = 0;
        dfs(0, 0, root, nodesMap, maxC, minC);
        int width = maxC - minC + 1; // -2 to 2 means -> (-2 -1 0 1 2) mapped to (0 1 2 3 4)
        vector<vector<int>> result(width);
        for (auto &it : nodesMap) {
            if (it.second.size() > 1) {
                sort(begin(it.second), end(it.second));
            }
            result[(-minC) + it.first[0]].insert(result[(-minC) + it.first[0]].end(), begin(it.second), end(it.second));
        }
        
        return result;
    }
    
    void dfs(int r, int c, TreeNode* cur, map<vector<int>, vector<int>> &nodesMap, int &maxC, int &minC) {
        if (cur == NULL) {
            return;
        }
        nodesMap[{c, r}].push_back(cur->val);
        maxC = max(maxC, c);
        minC = min(minC, c);
        dfs(r + 1, c - 1, cur->left, nodesMap, maxC, minC);
        dfs(r + 1, c + 1, cur->right, nodesMap, maxC, minC);
    }
};