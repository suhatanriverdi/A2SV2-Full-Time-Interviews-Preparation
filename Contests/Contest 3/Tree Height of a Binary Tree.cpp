// Question Link: https://www.hackerrank.com/contests/a2sv-contest-3/challenges/tree-height-of-a-binary-tree

int height(Node* root) {
    if (root == NULL) {
        return -1;
    }
    return 1 + max(height(root->right), height(root->left));
}