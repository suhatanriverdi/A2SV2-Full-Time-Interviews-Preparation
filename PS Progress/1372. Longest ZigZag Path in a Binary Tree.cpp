// Question Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

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