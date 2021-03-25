// Question Link: https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Accumulate row sum
        for (int i = 1; i < grid[0].size(); i++) {
            grid[0][i] += grid[0][i - 1];
        }
        // Accumulate col sum
        for (int i = 1; i < grid.size(); i++) {
            grid[i][0] += grid[i - 1][0];
        }
        // Find answer
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[i].size(); j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }   
        }
        return grid.back().back();
    }
};
