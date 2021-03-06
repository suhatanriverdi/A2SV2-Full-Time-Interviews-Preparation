// Question Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst

// With Early Termination
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int kthElement;
        bool found = false;
        helper(root, k, kthElement, found);
        return kthElement;
    }
    
    void helper(TreeNode* cur, int &k, int &kthElement, bool &found) {
        if (cur == NULL || found) {
            return;
        }
        helper(cur->left, k, kthElement, found);
        k--;
        if (k == 0) {
            found = true;
            kthElement = cur->val;
            return;
        }
        helper(cur->right, k, kthElement, found);
    }
};

// Without Early Termination
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int kthElement;
        helper(root, k, kthElement);
        return kthElement;
    }
    
    void helper(TreeNode* cur, int &k, int &kthElement) {
        if (cur == NULL) {
            return;
        }
        helper(cur->left, k, kthElement);
        k--;
        if (k == 0) {
            kthElement = cur->val;
            return;
        }
        helper(cur->right, k, kthElement);
    }
};
