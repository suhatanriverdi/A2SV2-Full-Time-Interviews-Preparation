// Question Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for (int &n : preorder) {
            root = insert(root, n);
        }
        return root;
    }
    
    TreeNode* insert(TreeNode* root, int &n) {
        if (root == NULL) {
            return new TreeNode(n);  
        }
        if (n > root->val) {
            root->right = insert(root->right, n);
        }
        else{
            root->left = insert(root->left, n);
        }
        return root;
    }
};