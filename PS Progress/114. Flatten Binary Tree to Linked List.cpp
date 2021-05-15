// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// O(1) Solution
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        TreeNode* R = root;
        while (R) {
            // Move left subtree to the right
            if (R->left) {
                TreeNode* ListPointer = R;
                moveToRight(R->left, &ListPointer, root);
                R->left = NULL;
            }
            R = R->right;
        }
    }
    
    void updateListPointer(TreeNode **ListPointer) {
        *ListPointer = (*ListPointer)->right;
    }
    
    // Pre-oerder traversal
    void moveToRight(TreeNode* cur, TreeNode** ListPointer, TreeNode* root) {
        if (cur == NULL) {
            return;
        }
        // Save right subtree
        TreeNode* tmp = (*ListPointer)->right;
        
        // Move current element to the right
        (*ListPointer)->right = new TreeNode(cur->val);
        
        // Move right subtree back
        (*ListPointer)->right->right = tmp;
        (*ListPointer)->right->left = NULL;
        
        // Update Listpointer
        updateListPointer(&(*ListPointer));
        
        moveToRight(cur->left, ListPointer, root);
        moveToRight(cur->right, ListPointer, root);
    }
};

// O(N) Solution
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        vector<int> LList;
        dfs(root, LList);
        root->left = NULL;
        root->right = NULL;
        TreeNode* walk = root;
        for (int i = 1; i < LList.size(); i++) {
            walk->left = NULL;
            walk->right = new TreeNode(LList[i]);
            walk = (walk ? walk->right : NULL);
        }
    }
    
    void dfs(TreeNode* cur, vector<int> &LList) {
        if (cur == NULL) {
            return;
        }
        LList.push_back(cur->val);
        dfs(cur->left, LList);
        dfs(cur->right, LList);
    }
};
