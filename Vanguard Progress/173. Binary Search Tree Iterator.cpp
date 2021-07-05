// Question Link: https://leetcode.com/problems/binary-search-tree-iterator

// O(1) Solution
class BSTIterator {
private:
    stack<TreeNode*> statesStack;
    
public:
    BSTIterator(TreeNode* root) {
        left(root);
    }
    
    void left(TreeNode* cur) {
        for (; cur; cur = cur->left) {
            statesStack.push(cur);
        }
    }
    
    int next() {
        TreeNode* curNext = statesStack.top();
        statesStack.pop();
        if (curNext->right) {
            left(curNext->right);
        }
        return curNext->val;
    }
    
    bool hasNext() {
        return statesStack.size() > 0;
    }
};

// Initial O(N) Solution
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
