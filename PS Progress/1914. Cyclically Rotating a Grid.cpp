// Question Link: https://leetcode.com/problems/cyclically-rotating-a-grid/

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int M = grid.size(), h = M;
        int N = grid[0].size(), w = N;
        int numOfLayers = min(M, N) / 2;
        // For each layer: 0,0 -> 1,1 ...
        for (int i = 0; i < numOfLayers; i++) {
            int numOfRotations = k % ((2 * h) + (2 * w) - 4);
            // Rotate each layer numOfRotations times
            for (int rotation = 0; rotation < numOfRotations; rotation++) {
                // Top row, left to right
                for (int j = i; j < N - i - 1; j++) {
                    swap(grid[i][j], grid[i][j + 1]);
                }
                // Right most col, from up to down
                for (int j = i; j < M - i - 1; j++) {
                    swap(grid[j][N - i - 1], grid[j + 1][N - i - 1]);
                }
                // Botttom row, from right to left
                for (int j = N - i - 1; j > i; j--) {
                    swap(grid[M - i - 1][j], grid[M - i - 1][j - 1]);
                }
                // Left most col, from down to up
                for (int j = M - i - 1; j > i + 1; j--) {
                    swap(grid[j][i], grid[j - 1][i]);
                }
            }
            h -= 2;
            w -= 2;
        }
        return grid;
    }
};