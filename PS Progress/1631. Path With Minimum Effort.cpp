// Question Link: https://leetcode.com/problems/path-with-minimum-effort/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int M = heights.size();
        int N = heights[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> todo;
        todo.push({INT_MAX, {0, 0, 0}});
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!todo.empty()) {
            pair<int, vector<int>> cur = todo.top();
            todo.pop();
            // Save the value for next calculation
            int prevValue = heights[cur.second[0]][cur.second[1]];
            // Mark as visited
            visited[cur.second[0]][cur.second[1]] = true;
            // Check if we reached to bottom right corner
            if (cur.second[0] == M - 1 && cur.second[1] == N - 1) {
                return cur.second[2];
            }
            for (vector<int> &dir : directions) {
                int nx = cur.second[0] + dir[0];
                int ny = cur.second[1] + dir[1];
                if (inside(nx, ny, M, N) && visited[nx][ny] == false) {
                    int newDiff = abs(prevValue - heights[nx][ny]);
                    int newMaximumAbsDiff = max(cur.second[2], newDiff);
                    todo.push({newDiff, {nx, ny, newMaximumAbsDiff}});
                }
            }
        }
        return 0;
    }
    
    bool inside(int x, int y, int &M, int &N) {
        if (x < 0 || x >= M || y < 0 || y >= N) {
            return false;
        }
        return true;
    }
};
