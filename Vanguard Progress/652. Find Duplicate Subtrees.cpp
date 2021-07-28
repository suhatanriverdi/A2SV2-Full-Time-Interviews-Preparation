// Question Link: https://leetcode.com/problems/find-duplicate-subtrees/

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

// More Concise Solution
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subTreeMap;
        vector<TreeNode*> sameSubtrees;
        postOrder(root, subTreeMap, sameSubtrees);
        return sameSubtrees;
    }
    
    string postOrder(TreeNode* cur, unordered_map<string, int> &subTreeMap, vector<TreeNode*> &sameSubtrees) {
        if (cur == nullptr) {
            return "";
        }
        
        string l = "L" + postOrder(cur->left, subTreeMap, sameSubtrees);
        string r = "R" + postOrder(cur->right, subTreeMap, sameSubtrees);
        string code = to_string(cur->val) + l + r;
        
        // Same subtree found
        if (subTreeMap[code] == 1) {
            sameSubtrees.push_back(cur);
        }
        subTreeMap[code]++;
        
        return code;
    }
};

// Initial Solution
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, bool> subTreeMap;
        vector<TreeNode*> sameSubtrees;
        postOrder(root, subTreeMap, sameSubtrees);
        return sameSubtrees;
    }
    
    string postOrder(TreeNode* cur, unordered_map<string, bool> &subTreeMap, vector<TreeNode*> &sameSubtrees) {
        if (cur == nullptr) {
            return "";
        }
        
        string l = "L" + postOrder(cur->left, subTreeMap, sameSubtrees);
        string r = "R" + postOrder(cur->right, subTreeMap, sameSubtrees);
        
        string code = to_string(cur->val) + l + r;
        
        // Same subtree found
        if (subTreeMap.find(code) != subTreeMap.end()) {
            if (subTreeMap[code] == false) {
                sameSubtrees.push_back(cur);
                // Mark this subtree as visited
                subTreeMap[code] = true;
            }
        }
        else {
            subTreeMap[code] = false;
        }
        
        return code;
    }
};