// Question Link: https://leetcode.com/problems/01-matrix/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        vector<vector<int>> directions = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        queue<vector<int>> todo;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j] == 0) {
                    getNeighborOnes(i, j, M, N, directions, mat, visited, todo);
                }
            }   
        }
        
        while (!todo.empty()) {
            bfs(M, N, directions, mat, todo, visited);
        }
        
        return mat;
    }
    
    void bfs(int &M, int &N, vector<vector<int>> &directions, vector<vector<int>> &mat, queue<vector<int>> &todo, vector<vector<bool>> &visited) {
        vector<int> cur = todo.front();
        todo.pop();
        for (vector<int> &dir : directions) {
            int ni = cur[0] + dir[0];
            int nj = cur[1] + dir[1];
            if (isValid(ni, nj, M, N, mat, visited)) {
                todo.push({ ni, nj, cur[2] + 1 });
                mat[ni][nj] = cur[2] + 1;
                visited[ni][nj] = true;
            }
        }
    }
    
    void getNeighborOnes(int i, int j, int &M, int &N, vector<vector<int>> &directions, vector<vector<int>> &mat, vector<vector<bool>> &visited, queue<vector<int>> &todo) {
        for (vector<int> &dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (isValid(ni, nj, M, N, mat, visited)) {
                todo.push({ ni, nj, 1 });
                visited[ni][nj] = true;
            }
        }
    }
    
    bool isValid(int i, int j, int &M, int &N, vector<vector<int>> &mat, vector<vector<bool>> &visited) {
        if (i < 0 || i >= M || j < 0 || j >= N || mat[i][j] != 1 || visited[i][j] == true) {
            return false;
        }
        return true;
    }
};