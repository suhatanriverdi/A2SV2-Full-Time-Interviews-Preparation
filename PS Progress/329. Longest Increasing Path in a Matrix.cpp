// Question Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
private:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, memo[201][201];
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int M = matrix.size();
        int N = matrix[0].size(), longestPath = 0;
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                longestPath = max(longestPath, dfs(i, j, matrix));
            }   
        }
        return longestPath;
    }
    
    int dfs(int i, int j, vector<vector<int>> &M) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int result = 1;
        for (auto dir : directions) {
            int ni = dir[0] + i;
            int nj = dir[1] + j;
            if (ni >= 0 && ni < M.size() && nj >= 0 && nj < M[0].size() && M[ni][nj] > M[i][j]) {
                result = max(dfs(ni, nj, M) + 1, result);
            }
        }
        memo[i][j] = result;
        return result;
    }
};