// Question Link: https://leetcode.com/problems/largest-magic-square/

class Solution {
private:
    // Prefix sums
    vector<vector<int>> preSumRow;
    vector<vector<int>> preSumCol;
    vector<vector<int>> preDiagLeftUpToRightDown;
    vector<vector<int>> preDiagRightUpToLeftDown;
public:
    int largestMagicSquare(vector<vector<int>> &grid) {
        int M = grid.size();
        int N = grid[0].size();
        if (M == 1 || N == 1) {
            return 1;
        }
        
        preSumRow = grid;
        preSumCol = grid;
        preDiagLeftUpToRightDown = grid;
        preDiagRightUpToLeftDown = grid;
        
        // prefix row sum
        for (int i = 0; i < M; i++) {
            for (int j = 1; j < N; j++) {
                preSumRow[i][j] += preSumRow[i][j - 1];
            }
        }
        
        // prefix col sum
        for (int i = 1; i < M; i++) {
            for (int j = 0; j < N; j++) {
                preSumCol[i][j] += preSumCol[i - 1][j];
            }
        }
        
        // prefix diagLeftUpToRightDown sum
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                preDiagLeftUpToRightDown[i][j] += preDiagLeftUpToRightDown[i - 1][j - 1];
            }
        }
        
        // prefix diagRightUpToLeftDown sum
        for (int i = 1; i < M; i++) {
            for (int j = N - 2; j >= 0; j--) {
                preDiagRightUpToLeftDown[i][j] += preDiagRightUpToLeftDown[i - 1][j + 1];
            }
        }
        
        // For all valid k*k squares, start from the largest valid square
        int k = min(M, N);
        while (k != 1) {
            for (int i = 0; i < M && (i + k - 1) < M; i++) {
                // If square fits in the grid, start searching
                for (int j = 0; j < N && (j + k - 1) < N; j++) {
                    if (isMagicSquare(i, j, k, M, N, grid)) {
                        return k;
                    }
                }
            }
            // Expand the square by 1
            k -= 1;
        }
        
        return 1;
    }
    
    bool isMagicSquare(int x, int y, int k, int &M, int &N, vector<vector<int>> &grid) {
        // preDiagLeftUpToRightDown
        int rightDownCorner = preDiagLeftUpToRightDown[x + k - 1][y + k - 1];
        int leftUpCorner = ((x - 1) >= 0 && (y - 1) >= 0) ? (preDiagLeftUpToRightDown[x - 1][y - 1]) : 0;
        int diagSumLeftUpToRightDown = rightDownCorner - leftUpCorner;
        
        // preDiagRightUpToLeftDown
        int leftDownCorner = preDiagRightUpToLeftDown[x + k - 1][y];
        int rightUpCorner = ((x - 1) >= 0 && (y + k) < N) ? (preDiagRightUpToLeftDown[x - 1][y + k]) : 0;
        int diagSumRightUpToLeftDown = leftDownCorner - rightUpCorner;
        
        // Check if all diagonal sums are equal
        if (diagSumLeftUpToRightDown != diagSumRightUpToLeftDown) {
            return false;
        }
        
        // Check if all row sums are equal
        for (int i = x + 1, t = k - 1; i < M && t > 0; i++, t--) {
            int curPrefixSum = preSumRow[i][y + k - 1] - ((y - 1) >= 0 ? preSumRow[i][y - 1] : 0);
            int prevPrefixSum = preSumRow[i - 1][y + k - 1] - ((y - 1) >= 0 ? preSumRow[i - 1][y - 1] : 0);
            if (curPrefixSum != prevPrefixSum || curPrefixSum != diagSumLeftUpToRightDown) {
                return false;
            }
        }
        
        // Check if all column sums are equal
        for (int j = y + 1, t = k - 1; j < N && t > 0; j++, t--) {
            int curPrefixSum = preSumCol[x + k - 1][j] - ((x - 1) >= 0 ? preSumCol[x - 1][j] : 0);
            int prevPrefixSum = preSumCol[x + k - 1][j - 1] - ((x - 1) >= 0 ? preSumCol[x - 1][j - 1] : 0);
            if (curPrefixSum != prevPrefixSum || curPrefixSum != diagSumLeftUpToRightDown) {
                return false;
            }
        }
        
        return true;
    }
};