// Question Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

// DFS Solution
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        helper(root, 'L', 0, ans);
        helper(root, 'R', 0, ans);
        return ans;
    }
    
    void helper(TreeNode* cur, char prevDir, int len, int &ans) {
        if (cur == NULL) {
            return;
        }
        
        ans = max(ans, len);
        
        helper(cur->left, (prevDir == 'R') ? 'L' : 'R', (prevDir == 'R') ? (len + 1) : 0, ans);
        helper(cur->right, (prevDir == 'L') ? 'R' : 'L', (prevDir == 'L') ? (len + 1) : 0, ans);
    }
};

// BFS Solution
struct info {
    TreeNode* node = NULL;
    char prevDirection = '\0';
    int zigZaglen = 0;
};

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        queue<info> todo;
        todo.push({ root, 'R', 0 });
        todo.push({ root, 'L', 0 });
        int longestZigZagLen = 0;
        while (!todo.empty()) {
            info cur = todo.front();
            todo.pop();
            
            // Update result
            longestZigZagLen = max(longestZigZagLen, cur.zigZaglen);
            
            // If we have right child         
            if (cur.node->right) {
                if (cur.prevDirection == 'L') {
                    todo.push({ cur.node->right, 'R', cur.zigZaglen + 1 });
                }
                else {
                    todo.push({ cur.node->right, 'L', 0 });
                }
            }
            
            // If we have left child
            if (cur.node->left) {
                if (cur.prevDirection == 'R') {
                    todo.push({ cur.node->left, 'L', cur.zigZaglen + 1 });
                }
                else {
                    todo.push({ cur.node->left, 'R', 0 });
                }
            }
        }
        
        return longestZigZagLen;
    }
};
