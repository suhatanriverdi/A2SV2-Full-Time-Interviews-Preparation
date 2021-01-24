// Question Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> A;
        inOrderTraversal(root, A);
        int result = A[1] - A[0];
        for (int i = 1; i < A.size(); i++) {
            result = min(A[i] - A[i - 1], result);
        }
        return result;
    }
    
    void inOrderTraversal(TreeNode* cur, vector<int> &A) {
        if (cur == NULL) {
            return;
        }
        inOrderTraversal(cur->left, A);
        A.push_back(cur->val);
        inOrderTraversal(cur->right, A);
    }
};
