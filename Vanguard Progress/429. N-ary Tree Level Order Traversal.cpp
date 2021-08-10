// Question Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> result = {{ root->val }};
        queue<Node*> todo;
        todo.push(root);
        while (!todo.empty()) {
            vector<int> level;
            for (int s = todo.size(); s > 0; s--) {
                Node* node = todo.front();
                todo.pop();
                for (Node* &child : node->children) {
                    level.push_back(child->val);
                    todo.push(child);
                }
            }
            if (!level.empty()) {
                result.push_back(level);
            }
        }
        return result;
    }
};