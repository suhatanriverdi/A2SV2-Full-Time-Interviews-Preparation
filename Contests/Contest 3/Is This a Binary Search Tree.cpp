// Question Link: https://www.hackerrank.com/contests/a2sv-contest-3/challenges/is-binary-search-tree/

void helper(Node* cur, vector<int> &A) {
    if (cur == NULL) {
        return;
    }
    helper(cur->left, A);
    A.push_back(cur->data);
    helper(cur->right, A);
}

bool checkBST(Node* root) {
    if (root == NULL) {
        return true;
    }
    vector<int> A;
    helper(root, A);
    for (int i = 1; i < A.size(); i++) {
        if (A[i] <= A[i - 1]) {
            return false;
        }
    }
    return true;
}