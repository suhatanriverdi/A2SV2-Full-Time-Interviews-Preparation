// Question Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

class Solution {
public:
    int maxProduct(TreeNode* root) {
        long long int result = 0, totalSum = getTotalSum(root);
        getMaxProduct(root, result, totalSum);
        return result % 1000000007;
    }
    
    long long int getMaxProduct(TreeNode* cur, long long int &maxProd, long long int &totalSum) {
        if (cur == NULL) {
            return 0;
        }
        long long int leftSubtreeSum = getMaxProduct(cur->left, maxProd, totalSum);
        long long int rightSubtreeSum = getMaxProduct(cur->right, maxProd, totalSum);
        if (cur->right) {
            long long int rest = totalSum - rightSubtreeSum;
            long long int prod = rest * rightSubtreeSum;
            maxProd = max(prod, maxProd);
        }
        if (cur->left) {
            long long int rest = totalSum - leftSubtreeSum;
            long long int prod = rest * leftSubtreeSum;
            maxProd = max(prod, maxProd);
        }
        return cur->val + leftSubtreeSum + rightSubtreeSum;
    }
    
    long long int getTotalSum(TreeNode* cur) {
        if (cur == NULL) {
            return 0;
        }
        return cur->val + getTotalSum(cur->left) + getTotalSum(cur->right);
    }
};
