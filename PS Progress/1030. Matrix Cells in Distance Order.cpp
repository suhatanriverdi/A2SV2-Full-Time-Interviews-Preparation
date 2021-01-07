// Question Link: https://leetcode.com/problems/matrix-cells-in-distance-order/

// Using Priority Queue
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> distPQ; // {dist, {x, y}}
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int dist = abs(i - r0) + abs(j - c0);
                distPQ.push({dist, {i, j}});
            }
        }
        while (!distPQ.empty()) {
            result.push_back(distPQ.top().second);
            distPQ.pop();
        }
        return result;
    }
};

// Using Multimap
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        multimap<int, vector<int>> distMap; // {dist, {x, y}}
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int dist = abs(i - r0) + abs(j - c0);
                distMap.insert({dist, {i, j}});
            }
        }
        for (auto it : distMap) {
            result.push_back(it.second);
        }
        return result;
    }
};

// BFS Solution
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> distances = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> visited(R, vector<int>(C, 0));
        vector<vector<int>> result(R * C, vector<int>(2, 0));
        int currentPair = 0;
        queue<vector<int>> toDo;
        toDo.push({r0, c0});
        visited[r0][c0] = 1; // Mark starting point as visited
        result[currentPair++] = {r0, c0};
        while (!toDo.empty()) {
            vector<int> cur = toDo.front();
            toDo.pop();
            for (vector<int> dist : distances) {
                int nx = cur[0] + dist[0];
                int ny = cur[1] + dist[1];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C || visited[nx][ny] == 1) {} 
                else {
                    toDo.push({nx, ny});
                    visited[nx][ny] = 1;
                    result[currentPair++] = {nx, ny};
                }
            }
        }
        return result;
    }
};
