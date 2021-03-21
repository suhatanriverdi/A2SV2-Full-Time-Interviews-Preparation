// Question Link: https://www.hackerrank.com/challenges/journey-to-the-moon/problem

long long int dfs(int cur, vector<vector<int>> &graph, vector<bool> &seen) {
    seen[cur] = true;
    long long int count = 1;
    for (int &neigh : graph[cur]) {
        if (seen[neigh] == false) {
            count += dfs(neigh, graph, seen);
        }
    }
    return count;
}

// Complete the journeyToMoon function below.
long long int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<vector<int>> graph(n);
    for (vector<int> &a : astronaut) {
        graph[a[0]].push_back(a[1]);
        graph[a[1]].push_back(a[0]);        
    }
    long long int result = 0, prev = 0;
    vector<bool> seen(n, false);
    for (int i = 0; i < n; i++) {
        if (seen[i] == false) {
            long long int count = dfs(i, graph, seen);
            result += count * prev;
            prev = count + prev;
        }
    }
    return result;
}
