// Question Link: https://leetcode.com/problems/binary-search-tree-iterator

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
class BSTIterator {
private:
    int it = 0;
    vector<int> elements;
public:
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }
    
    void inOrder(TreeNode* cur) {
        if (cur == NULL) {
            return;
        }
        inOrder(cur->left);
        elements.push_back(cur->val);
        inOrder(cur->right);
    }
    
    int next() {
        return elements[it++];
    }
    
    bool hasNext() {
        return it < elements.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */