// Question Link: https://leetcode.com/problems/as-far-from-land-as-possible/

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
};
