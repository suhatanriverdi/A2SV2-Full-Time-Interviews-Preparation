// Question Link: https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        if (grid[0][0] == 1) {
            return -1;
        }
        queue<vector<int>> todo;
        todo.push({0, 0});
        grid[0][0] = 1; // Marks starting cell as visited
        while (!todo.empty()) {
            vector<int> cur = todo.front();
            todo.pop();
            if (cur[0] == M - 1 && cur[1] == N - 1) {
                return grid[cur[0]][cur[1]];
            }
            for (vector<int> &dir : dirs) {
                int nx = dir[0] + cur[0];
                int ny = dir[1] + cur[1];
                if (nx >= 0 && nx < M && ny >= 0 && ny < N && grid[nx][ny] == 0) {
                    grid[nx][ny] = grid[cur[0]][cur[1]] + 1;
                    todo.push({nx, ny});
                }
            }
        }
        return -1;
    }
};