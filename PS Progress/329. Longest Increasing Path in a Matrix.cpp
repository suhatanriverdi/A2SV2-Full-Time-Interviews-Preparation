// Question Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
private:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        // We only need to have end nodes of the possible paths
        queue<vector<int>> endNodes;
        // This keeps track of the path lenghts during the BFS and visited case
        vector<vector<int>> maxSeen(M, vector<int>(N, 0));
        // Find the nodes that has no outgoing edges
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (isEndNode(matrix, r, c)) {
                    endNodes.push({r, c});
                    // Mark the starting lenght as 1 at the end of paths
                    maxSeen[r][c] = 1;
                }
            }   
        }
        int longestPathLenght = 1;
        // Run BFS to get longest path lenght
        while (!endNodes.empty()) {
            vector<int> cur = endNodes.front();
            endNodes.pop();
            // Check our 4 neighbors, keep going from smaller ones
            for (vector<int> &dir : dirs) {
                int nx = dir[0] + cur[0];
                int ny = dir[1] + cur[1];
                // If our neighbor is smaller than us and not visited yet
                if (inside(matrix, nx, ny) && matrix[nx][ny] < matrix[cur[0]][cur[1]] && maxSeen[cur[0]][cur[1]] + 1 > maxSeen[nx][ny]) {
                    endNodes.push({nx, ny});
                    maxSeen[nx][ny] = maxSeen[cur[0]][cur[1]] + 1;
                    longestPathLenght = max(longestPathLenght, maxSeen[nx][ny]);
                }
            }
        }
        return longestPathLenght;
    }
    
    // Check if we are bigger than our 4 directionally neighbors
    bool isEndNode(vector<vector<int>> &M, int &x, int &y) {
        for (vector<int> &dir : dirs) {
            int nx = dir[0] + x;
            int ny = dir[1] + y;
            if (inside(M, nx, ny) && M[x][y] < M[nx][ny]) {
                return false;
            }
        }
        return true;
    }
    
    // Check if we are inside
    bool inside(vector<vector<int>> &M, int &x, int &y) {
        if (x < 0 || x >= M.size() || y < 0 || y >= M[0].size()) {
            return false;
        }
        return true;
    }
};