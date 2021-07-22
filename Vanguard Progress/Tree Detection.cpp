// Question https://binarysearch.com/problems/Tree-Detection

void dfs(int cur, vector<int> &left, vector<int> &right, unordered_set<int> &seen, bool &hasCycle) {
    // Cycle found
    if (seen.find(cur) != seen.end()) {
        hasCycle = true;
        return;
    }
    seen.insert(cur);
    if (left[cur] != -1) {
        dfs(left[cur], left, right, seen, hasCycle);
    }
    if (right[cur] != -1) {
        dfs(right[cur], left, right, seen, hasCycle);
    }
}

int findRoot(vector<int> &left, vector<int> &right, int &len) {
    vector<int> nodes(len, 0);
    for (int i = 0; i < len; i++) {
        if (left[i] != -1) {
            nodes[left[i]]++;
        }
        if (right[i] != -1) {
            nodes[right[i]]++;
        }
    }
    for (int i = 0; i < len; i++) {
        if (nodes[i] == 0) {
            return i;
        }
    }
    return -1;
}

bool solve(vector<int>& left, vector<int>& right) {
    int numOfNodes = right.size();
    if (numOfNodes == 0) {
        return true;
    }
    unordered_set<int> seen;
    bool hasCycle = false;
    int root = findRoot(left, right, numOfNodes);
    dfs(root, left, right, seen, hasCycle);
    // If we visit all the nodes and there is no cycle means that it is a binary tree
    return seen.size() == numOfNodes && hasCycle == false;
}