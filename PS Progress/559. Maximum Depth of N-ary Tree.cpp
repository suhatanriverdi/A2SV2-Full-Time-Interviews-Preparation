// Question Link: https://leetcode.com/problems/maximum-depth-of-n-ary-tree

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int localMaxDepth = 1;
        for (Node* &child : root->children) {
            localMaxDepth = max(1 + maxDepth(child), localMaxDepth);
        }
        return localMaxDepth;
    }
};
