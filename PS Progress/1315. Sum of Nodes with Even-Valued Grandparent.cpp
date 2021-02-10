// Question Link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int evenGrandparentSum = 0;
        helper(root, evenGrandparentSum);
        return evenGrandparentSum;
    }
    
    void helper(TreeNode* cur, int &sum) {
        if (cur == NULL) {
            return;
        }
        if ((cur->val & 1) == 0) {
            if (cur->left) {
                sum += (cur->left->left ? cur->left->left->val : 0);
                sum += (cur->left->right ? cur->left->right->val : 0);
            }
            if (cur->right) {
                sum += (cur->right->left ? cur->right->left->val : 0);
                sum += (cur->right->right ? cur->right->right->val : 0);
            }
        }
        helper(cur->left, sum);
        helper(cur->right, sum);
    }
};