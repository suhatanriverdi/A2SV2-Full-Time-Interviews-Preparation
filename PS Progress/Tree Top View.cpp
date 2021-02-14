// Question Link: https://www.hackerrank.com/challenges/tree-top-view/problem

void topView(Node *root) {
    queue<pair<Node*, int>> todo;
    todo.push({root, 0});
    vector<int> counts(500, 0);
    while (!todo.empty()) {
        pair<Node*, int> cur = todo.front();
        todo.pop();
        if (counts[cur.second + 250] == 0) {
            counts[cur.second + 250] = cur.first->data;
        }
        if (cur.first->left) {
            todo.push({cur.first->left, cur.second - 1});            
        }
        if (cur.first->right) {
            todo.push({cur.first->right, cur.second + 1});          
        }
    }
    for (int &c : counts) {
        if (c > 0) {
            cout << c << " ";
        }
    }
}