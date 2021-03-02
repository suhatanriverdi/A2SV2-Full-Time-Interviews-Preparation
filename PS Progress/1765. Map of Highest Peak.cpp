// Question Link: https://leetcode.com/problems/map-of-highest-peak/

class Solution {
private:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int M = isWater.size(), N = isWater[0].size();
        queue<vector<int>> todo;
        bool seen[1001][1001] = {false};
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (isWater[r][c] == 1) {
                    todo.push({r, c});
                    isWater[r][c] = 0;
                    seen[r][c] = true;
                }
            }   
        }
        while (!todo.empty()) {
            vector<int> cur = todo.front();
            todo.pop();
            for (vector<int> &dir : dirs) {
                int nx = dir[0] + cur[0];
                int ny = dir[1] + cur[1];
                if (nx >= 0 && nx < M && ny >= 0 && ny < N && isWater[nx][ny] == 0 && seen[nx][ny] == false) {
                    isWater[nx][ny] = isWater[cur[0]][cur[1]] + 1;
                    todo.push({nx, ny});
                }
            }
        }
        return isWater;
    }
};