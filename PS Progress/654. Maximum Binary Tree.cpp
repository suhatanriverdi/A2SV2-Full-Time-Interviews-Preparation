// Question Link: https://leetcode.com/problems/maximum-binary-tree/

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    
    TreeNode* helper(vector<int> &n, int l, int r) {
        if (l > r) {
            return NULL;
        }
        // Find max element
        auto it = max_element(begin(n) + l, begin(n) + r + 1);
        int maxIndex = distance(begin(n), it);
        // Create node
        TreeNode* root = new TreeNode(n[maxIndex]);
        root->left = helper(n, l, maxIndex - 1);
        root->right = helper(n, maxIndex + 1, r);
        return root;
    }
};
