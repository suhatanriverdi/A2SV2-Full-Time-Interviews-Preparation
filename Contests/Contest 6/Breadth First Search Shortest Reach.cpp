// Question Link: https://www.hackerrank.com/challenges/bfsshortreach/problem

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<int>> graph(n + 1, vector<int>());
    for (vector<int> edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    queue<vector<int>> todo; // {node, dist} 
    todo.push({s, 0});
    vector<bool> seen(n + 1, false);
    seen[s] = true; // Mark starting node as vidited
    map<int, int> nodeDist; // {node in sorted, distance}
    vector<int> result;
    while (!todo.empty()) {
        vector<int> cur = todo.front();
        todo.pop();
        for (int &neigh : graph[cur[0]]) {
            if (seen[neigh] == false) {
                todo.push({neigh, cur[1] + 6});
                seen[neigh] = true;
                nodeDist[neigh] = cur[1] + 6;
            }
        }
    }
    for (int i = 1; i < seen.size(); i++) {
        if (seen[i] == false) {
            nodeDist[i] = -1;
        }
    }
    for (auto it : nodeDist) {
        result.push_back(it.second);
    }
    return result;
}