// Question Link: https://leetcode.com/problems/rotting-oranges/

class Solution {
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int M = grid.size(), latestMinute = 0;
        int N = grid[0].size();
        queue<vector<int>> todo;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                // Start BFS from rotten oranges
                if (grid[i][j] == 2) {
                    todo.push({i, j});
                }
            }
        }
        bfs(grid, todo, latestMinute);
        // Check if there is any fresh oranges after BFS
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        // Check 0 case, if there is no fresh orange
        return (latestMinute == 0 ? 0 : latestMinute - 2);
    }
    
    // Run BFS and return the greatest minutes
    void bfs(vector<vector<int>> &grid, queue<vector<int>> &todo, int &latestMinute) {
        while (!todo.empty()) {
            vector<int> cur = todo.front();
            todo.pop();
            for (vector<int> &dir : dirs) {
                int nx = dir[0] + cur[0];
                int ny = dir[1] + cur[1];        
                if (inside(nx, ny, grid) && grid[nx][ny] == 1) {
                    grid[nx][ny] = grid[cur[0]][cur[1]] + 1;
                    // Update Latest Minute
                    latestMinute = max(latestMinute, grid[nx][ny]);
                    todo.push({nx, ny});
                }
            }
        }
    }
    
    bool inside(int x, int y, vector<vector<int>> &grid) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
            return false;
        }
        return true;
    }
};
