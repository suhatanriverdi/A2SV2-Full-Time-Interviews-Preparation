// Question Link: https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
    int M, N;
    vector<vector<int>> firstRowColOnlyPrefix, lastRowColOnlyPrefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        M = matrix.size();
        N = matrix[0].size();
        
        firstRowColOnlyPrefix = matrix;
        lastRowColOnlyPrefix = matrix;
        
        // Build prefix first & last row sum
        for (int j = 1; j < N; j++) {
            // Fill first row from left to right
            firstRowColOnlyPrefix[0][j] += firstRowColOnlyPrefix[0][j - 1];
            // Fill last row from right to left
            lastRowColOnlyPrefix[M - 1][N - 1 - j] += lastRowColOnlyPrefix[M - 1][N - 1 - j + 1];
        }
        
        // Build prefix first & last col sum
        for (int i = 1; i < M; i++) {
            // Fill first col from up to down
            firstRowColOnlyPrefix[i][0] += firstRowColOnlyPrefix[i - 1][0];
            // Fill first col from up to down
            lastRowColOnlyPrefix[M - i - 1][N - 1] += lastRowColOnlyPrefix[M - i - 1 + 1][N - 1];
        }   
        
        // Build left up _| & right down ┌ prefix sum
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                // Left Up
                firstRowColOnlyPrefix[i][j] += firstRowColOnlyPrefix[i - 1][j] + firstRowColOnlyPrefix[i][j - 1] - firstRowColOnlyPrefix[i - 1][j - 1];
                // Right Down
                lastRowColOnlyPrefix[M - i - 1][N - j - 1] += lastRowColOnlyPrefix[M - i - 1][N - j] + lastRowColOnlyPrefix[M - i][N - j - 1] - lastRowColOnlyPrefix[M - i][N - j];
            }
        } 
    }
    
    // Returns region sum in O(1)
    int sumRegion(int r1, int c1, int r2, int c2) {
        int regionSum = 0, totalSum = lastRowColOnlyPrefix[0][0];
        int A = (c1 - 1 >= 0) ? firstRowColOnlyPrefix[M - 1][c1 - 1] : 0;
        int B = (c2 + 1 < N) ? lastRowColOnlyPrefix[0][c2 + 1] : 0;
        int C = ((r1 - 1 >= 0) ? firstRowColOnlyPrefix[r1 - 1][c2] : 0) - ((r1 - 1 >= 0) && (c1 - 1 >= 0) ? firstRowColOnlyPrefix[r1 - 1][c1 - 1] : 0);
        int D = ((r2 + 1 < M) ? lastRowColOnlyPrefix[r2 + 1][c1] : 0) - ((c2 + 1 < N) && (r2 + 1 < M) ? lastRowColOnlyPrefix[r2 + 1][c2 + 1] : 0);
        regionSum = totalSum - (A + B + C + D);
        return regionSum;
    }
};