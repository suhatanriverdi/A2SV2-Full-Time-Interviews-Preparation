// Question Link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

// Solution 1
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

// Solution 2
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        return helper(root, 1, 1);
    }
    
    int helper(TreeNode* cur, int parent, int grandParent) {
        if (cur == NULL) {
            return 0;
        }
        int curContribution = (!(grandParent & 1) ? cur->val : 0);
        return curContribution + helper(cur->left, cur->val, parent) + helper(cur->right, cur->val, parent);
    }
};

// Solution 3
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        helper(root, 1, 1, sum);
        return sum;
    }
    
    void helper(TreeNode* cur, int parent, int grandParent, int &sum) {
        if (cur == NULL) {
            return;
        }
        sum += (!(grandParent & 1) ? cur->val : 0);
        helper(cur->left, cur->val, parent, sum);
        helper(cur->right, cur->val, parent, sum);
    }
};
