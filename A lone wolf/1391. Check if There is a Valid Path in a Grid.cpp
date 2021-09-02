// Question Link: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();        
                                          // 0        1        2        3
                                          // Up     Right    Down     Left
        vector<vector<int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
        
        // The neighbors we can go
        unordered_map<int, vector<int>> canGo = {
            { 1, {1, 3} }, // { sign, { new positions } }
            { 2, {0, 2} },
            { 3, {3, 2} },
            { 4, {2, 1} },
            { 5, {3, 0} },
            { 6, {0, 1} }
        };
        
        unordered_map<int, unordered_map<int, unordered_set<int>>> validStreets = {
            { 1, { { {1, {1, 3, 5}}, {3, {1, 4, 6}} } } }, // { sign, { valid signs we can jump to } }
            { 2, { { {0, {2, 3, 4}}, {2, {2, 5, 6}} } } },
            { 3, { { {3, {1, 4, 6}}, {2, {2, 5, 6}} } } },
            { 4, { { {2, {2, 5, 6}}, {1, {1, 3, 5}} } } },
            { 5, { { {3, {1, 4, 6}}, {0, {2, 3, 4}} } } },
            { 6, { { {0, {2, 3, 4}}, {1, {1, 3, 5}} } } }
        };
            
        queue<vector<int>> todo;
        todo.push({ 0, 0 });
        
        while (!todo.empty()) {
            
            vector<int> cur = todo.front();
            todo.pop();
            
            int x = cur[0];
            int y = cur[1];
            
            if (x == M - 1 && y == N - 1) {
                return true;
            }
            
            int sign = grid[cur[0]][cur[1]];
            grid[cur[0]][cur[1]] = -1;
            
            vector<int> possibleNeighbors = canGo[sign];
            for (int &direction : possibleNeighbors) {
                
                int nx = x + directions[direction][0];
                int ny = y + directions[direction][1];
                
                if (isInside(nx, ny, M, N, grid) && validStreets[sign][direction].count(grid[nx][ny]) > 0) {
                    todo.push({ nx, ny });
                }
            }
        }
        
        return false;
    }
    
    bool isInside(int nx, int ny, int &M, int &N, vector<vector<int>>& grid) {
        if (nx < 0 || nx >= M || ny < 0 || ny >= N || grid[nx][ny] == -1) {
            return false;
        }
        return true;
    }
};