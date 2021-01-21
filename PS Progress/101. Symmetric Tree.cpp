// Question Link: https://leetcode.com/problems/symmetric-tree/

// Recursive Solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root, root);
    }
    
    bool isSymmetricHelper(TreeNode* a, TreeNode* b) {
        if (a == NULL && b == NULL) {
            return true;
        }
        if ((a && !b) || (!a && b)) {
            return false;
        }
        if (a->val != b->val) {
            return false;
        }
        return isSymmetricHelper(a->left, b->right) && isSymmetricHelper(a->right, b->left);
    }
};

// Iterative Solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<string> s;
            for (int l = q.size(); l > 0; l--) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->right) {
                    q.push(cur->right);
                    s.push_back(to_string(cur->right->val));
                }
                else {
                    s.push_back("n");
                }
                if (cur->left) {
                    q.push(cur->left);
                    s.push_back(to_string(cur->left->val));
                } 
                else {
                    s.push_back("n");
                }
            }
            if (isPalindrome(s) == false) {
                return false;
            }
        }
        return true;
    }
    
    bool isPalindrome(vector<string> &s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};
