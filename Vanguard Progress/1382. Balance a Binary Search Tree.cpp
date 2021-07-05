// Question Link: https://leetcode.com/problems/balance-a-binary-search-tree/

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedElements;
        inOrder(root, sortedElements);
        return insertBalanced(sortedElements, 0, sortedElements.size() - 1);
    }

    TreeNode* insertBalanced(vector<int> &sortedElements, int l, int r) {
        if (l > r) {
            return NULL;
        }
        
        int mid = l + (r - l) / 2;

        TreeNode* root = new TreeNode(sortedElements[mid]);

        // Go left
        root->left = insertBalanced(sortedElements, l, mid - 1);

        // Go right
        root->right = insertBalanced(sortedElements, mid + 1, r);
        
        return root;
    }
    
    void inOrder(TreeNode* cur, vector<int> &sortedElements) {
        if (cur == NULL) {
            return;
        }
        inOrder(cur->left, sortedElements);
        sortedElements.push_back(cur->val);
        inOrder(cur->right, sortedElements);
    }
};