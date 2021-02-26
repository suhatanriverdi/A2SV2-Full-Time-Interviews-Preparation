// Question Link: https://www.hackerrank.com/challenges/beautiful-path/problem

// Normal Queue Solution (No need to use PQ)
int beautifulPath(vector<vector<int>> edges, int A, int B) {
    vector<vector<pair<int, int>>> graph(10e4 + 1); // {node, {child, weight}}
    vector<vector<bool>> seen(10e4 + 1, vector<bool>(1024, false)); // {node, {with what weight we came}}
    for (vector<int> &edge : edges) {
        graph[edge[0]].push_back({edge[1], edge[2]});
        graph[edge[1]].push_back({edge[0], edge[2]});
    }
    int penaltyCost = INT_MAX;
    queue<vector<int>> todo; // {weight, node} minHeap
    todo.push({0, A});
    seen[A][0] = true; // Assume we reached node A with 0 total weight
    while (!todo.empty()) {
        vector<int> cur = todo.front();
        todo.pop();
        // If we reach target, save min penalty
        if (cur[1] == B) {
            penaltyCost = min(penaltyCost, cur[0]);
        }
        for (pair<int, int> &child : graph[cur[1]]) {
            if (seen[child.first][cur[0] | child.second] == false) {
                // Update new weight by OR'ing with parent's weight
                todo.push({cur[0] | child.second, child.first});
                seen[child.first][cur[0] | child.second] = true;
            }
        }
    }
    return (penaltyCost == INT_MAX ? -1 : penaltyCost);
}

// PQ Solution
class Solution {
private:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size(), maxDist = -1;
        queue<vector<int>> todo;
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] == 1) {
                    todo.push({r, c});
                }
            }   
        }
        while (!todo.empty()) {
            vector<int> cur = todo.front();
            todo.pop();
            for (vector<int> &dir : dirs) {
                int nx = dir[0] + cur[0];
                int ny = dir[1] + cur[1];
                if (nx >= 0 && nx < M && ny >= 0 && ny < N && grid[nx][ny] == 0) {
                    grid[nx][ny] = grid[cur[0]][cur[1]] + 1;
                    todo.push({nx, ny});
                    maxDist = max(grid[nx][ny] - 1, maxDist);
                }
            }
        }
        return maxDist;
    }
};// Complete the beautifulPath function below.
int beautifulPath(vector<vector<int>> edges, int A, int B) {
    vector<vector<pair<int, int>>> graph(10e4 + 1); // {node, {child, weight}}
    vector<vector<bool>> seen(10e4 + 1, vector<bool>(1024, false)); // {node, {with what weight we came}}
    for (vector<int> &edge : edges) {
        graph[edge[0]].push_back({edge[1], edge[2]});
        graph[edge[1]].push_back({edge[0], edge[2]});
    }
    int penaltyCost = INT_MAX;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> todo; // {weight, node} minHeap
    todo.push({0, A});
    seen[A][0] = true; // Assume we reached node A with 0 total weight
    while (!todo.empty()) {
        vector<int> cur = todo.top();
        todo.pop();
        // If we reach target, save min penalty
        if (cur[1] == B) {
            penaltyCost = min(penaltyCost, cur[0]);
        }
        for (pair<int, int> &child : graph[cur[1]]) {
            if (seen[child.first][cur[0] | child.second] == false) {
                // Update new weight by OR'ing with parent's weight
                todo.push({cur[0] | child.second, child.first});
                seen[child.first][cur[0] | child.second] = true;
            }
        }
    }
    return (penaltyCost == INT_MAX ? -1 : penaltyCost);
}
