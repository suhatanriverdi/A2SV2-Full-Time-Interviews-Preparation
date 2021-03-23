// Question Link: https://leetcode.com/problems/triangle/

// Top-Down Recursive Solution O(NM)/2 Time & O(NM) Space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int M = triangle.size();
        vector<vector<int>> memo(M, vector<int>(M, -1));
        if (M == 1) {
            return triangle[0][0];
        }
        return dpHelper(0, 0, triangle, memo);
    }
    
    int dpHelper(int r, int c, vector<vector<int>> &T, vector<vector<int>> &memo) {
        if (memo[r][c] != -1) {
            return memo[r][c];
        }
        // Base case
        if (r == T.size() - 2) {
            memo[r][c] = T[r][c] + min(T[r + 1][c], T[r + 1][c + 1]);
            return memo[r][c];
        }
        memo[r][c] = T[r][c] + min(dpHelper(r + 1, c, T, memo), dpHelper(r + 1, c + 1, T, memo));
        return memo[r][c];
    }
};

// Bottom-Up Solution O(N*M)/2 Time & O(N) Space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int M = triangle.size();
        if (M == 1) {
            return triangle[0][0];
        }
        vector<int> row = triangle.back();
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                row[j] = triangle[i][j] + min(row[j], row[j + 1]);
            }   
        }
        return row[0];
    }
};

// Bottom-Up Solution O(N*M)/2 Time & O(1) Space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }   
        }
        return triangle[0][0];
    }
};
