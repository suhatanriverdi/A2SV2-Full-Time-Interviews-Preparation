// Question Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        TreeNode* root = NULL;
        return findMid(root, nums, 0, len - 1);
    }
    
    TreeNode* findMid(TreeNode* root, vector<int> &nums, int l, int r) {
        if (l <= r) {
            // Find mid value for current subarray
            int m = l + (r - l) / 2;
            // Insert mid value
            root = insert(root, nums[m]);
            // Go left
            root = findMid(root, nums, l,  m - 1);
            // Go right
            root = findMid(root, nums, m + 1,  r);
        }
        return root;
    }
    
    TreeNode* insert(TreeNode *cur, int &val) {
        TreeNode* newNode = new TreeNode(val);
        if (cur == NULL) {
            cur = new TreeNode(val);
            return cur;
        }
        // Go right
        if (val > cur->val) {
            cur->right = insert(cur->right, val);
        }
        // Go left
        else {
            cur->left = insert(cur->left, val);
        }
        return cur;
    }
};