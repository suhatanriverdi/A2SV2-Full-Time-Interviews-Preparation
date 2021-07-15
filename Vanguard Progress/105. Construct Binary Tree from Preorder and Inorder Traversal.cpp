// Question https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inOrderIndicesMap;
        int len = inorder.size();
        // Get the indices of values on inOrder array to access them in O(1) laster on
        for (int i = 0; i < len; i++) {
            inOrderIndicesMap[inorder[i]] = i;
        }
        
        // Create the root of the new tree
        TreeNode* root = new TreeNode(preorder[0]);
        
        // Create a stack to remember the most recent parents
        stack<pair<TreeNode*, int>> nodeIndexStack;
        nodeIndexStack.push({ root, inOrderIndicesMap[preorder[0]] });
        
        // Marked the node as done
        inorder[inOrderIndicesMap[preorder[0]]] = 9999;
        
        // For each node in preOrder array
        for (int i = 1; i < len; i++) {
            // Get the most recent parent from the stack
            TreeNode* mostRecentParent = nodeIndexStack.top().first;
            int mostRecentParentIndex = nodeIndexStack.top().second;
            
            // Current Child
            int currentVal = preorder[i];
            int currentIndex = inOrderIndicesMap[currentVal];
            
            // Left Child
            if (currentIndex < mostRecentParentIndex) {
                mostRecentParent->left = new TreeNode(currentVal);
                // Push current node
                nodeIndexStack.push({ mostRecentParent->left, currentIndex });
            }
            
            // Right Child
            else {
                mostRecentParent->right = new TreeNode(currentVal);
                // Push current node
                nodeIndexStack.push({ mostRecentParent->right, currentIndex });
            }
            
            // Marked as done
            inorder[currentIndex] = 9999;
            
            // Pop finished nodes
            while (!nodeIndexStack.empty() && finished(nodeIndexStack.top().second, len, inorder)) {
                nodeIndexStack.pop();
            }
        }
        return root;
    }
    
    bool finished(int &nodeIndex, int &len, vector<int> &inorder) {
        if ((nodeIndex - 1 == -1 || inorder[nodeIndex - 1] == 9999) &&
           (nodeIndex + 1 == len || inorder[nodeIndex + 1] == 9999)) {
            return true;
        }
        return false;
    }
};