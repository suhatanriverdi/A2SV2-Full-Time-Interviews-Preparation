// Question Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        TreeNode* LListRoot = new TreeNode(1453); // Create dummy Node
        TreeNode* tail = LListRoot;
        
        preOrder(root, &tail);
        
        LListRoot = LListRoot->right;
        
        root->left = NULL;
        root->right = LListRoot->right;
    }
    
    void preOrder(TreeNode* cur, TreeNode** tail) {
        if (cur == NULL) {
            return;
        }
        insert(&(*tail), cur->val);
        preOrder(cur->left, tail);
        preOrder(cur->right, tail);
    }
    
    void insert(TreeNode** tail, int val) {
        (*tail)->right = new TreeNode(val);
        *tail = (*tail)->right;
    }
};