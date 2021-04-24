// Question Link: https://www.hackerrank.com/challenges/components-in-graph/problem

int dfs(int cur, vector<vector<int>> &g, vector<bool> &seen) {
    seen[cur] = true;
    int result = 1;
    for (int &neigh : g[cur]) {
        if (seen[neigh] == false) {
            result += dfs(neigh, g, seen);
        }
    }
    return result;
}

vector<int> componentsInGraph(vector<vector<int>> gb) {
    int N = gb.size();
    vector<vector<int>> g(2 * N + 1);
    for (vector<int> &n : gb) {
        g[n[0]].push_back(n[1]);
        g[n[1]].push_back(n[0]);
    }
    int smallest = INT_MAX, biggest = 0;
    vector<bool> seen(N * 2, false);
    for (int i = 1; i <= N; i++) {
        int count;
        if (seen[i] == false) {
            count = dfs(i, g, seen);
            if (count >= 2) {
                smallest = min(smallest, count);
            }
            biggest = max(biggest, count);
        }
    }
    if (smallest == INT_MAX) {
        smallest = biggest;
    }
    return {smallest, biggest};
}