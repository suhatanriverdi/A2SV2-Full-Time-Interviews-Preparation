// Question https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
        return helper(nums, 0, nums.size() - 1);
    }
    
    TreeNode* helper(vector<int> &nums, int l, int r) {
        // Base case
        if (l > r) {
            return nullptr;
        }
        
        // Get the middle node
        int mid = l + (r - l) / 2;
        
        // Create a new node with middle value
        TreeNode* newNode = new TreeNode(nums[mid]);

        // Go the Left part
        newNode->left = helper(nums, l, mid - 1);

        // Go the Right part
        newNode->right = helper(nums, mid + 1, r);
        
        // Return newly created node
        return newNode;
    }
};