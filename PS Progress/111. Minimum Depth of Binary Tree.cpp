// Question Link: https://leetcode.com/problems/minimum-depth-of-binary-tree

// Solution 1 Using BFS (The Fastest in terms of Time Complexity but Long in Code)
class Solution {
public:
    int minDepth(TreeNode* root) {
        int minimumDepth = 1;
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            for (int size = todo.size(); size > 0; size--) {
                TreeNode* cur = todo.front();
                todo.pop();
                if (isLeaf(cur)) {
                    return minimumDepth;
                }
                if (cur->left) {
                    todo.push(cur->left);
                }
                if (cur->right) {
                    todo.push(cur->right);
                }
            }
            minimumDepth++;
        }
        return minimumDepth;
    }
    
    bool isLeaf(TreeNode* cur) {
        return !cur->left && !cur->right;
    }
};

// Solution 2 Using DFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return dfs(root);
    }
    
    int dfs(TreeNode* cur) {
        if (isLeaf(cur)) {
            return 1;
        }
        int leftDepth = (cur->left == NULL ? 10e5 : dfs(cur->left));
        int rightDepth = (cur->right == NULL ? 10e5 : dfs(cur->right));
        return min(leftDepth, rightDepth) + 1;
    }
    
    bool isLeaf(TreeNode* cur) {
        return !cur->left && !cur->right;
    }
};

// Solution 3 Using DFS and Passing Value by Reference
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int minimumDepth = 10e5;
        dfs(root, minimumDepth, 1);
        return minimumDepth;
    }
    
    void dfs(TreeNode* cur, int &minDepth, int curDepth) {
        if (isLeaf(cur)) {
            minDepth = min(minDepth, curDepth);
            return;
        }
        if (cur->left) {
            dfs(cur->left, minDepth, curDepth + 1);
        }
        if (cur->right) {
            dfs(cur->right, minDepth, curDepth + 1);
        }
    }
    
    bool isLeaf(TreeNode* cur) {
        return !cur->left && !cur->right;
    }
};

// Solution 4 Using Recursion The Shortest Code | Concise
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL) {
            return 1 + minDepth(root->right);
        }
        if (root->right == NULL) {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};