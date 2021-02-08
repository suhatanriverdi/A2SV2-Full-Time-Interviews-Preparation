// Question Link: https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size(), maxArea = 0, currentArea;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // Area found, start calculating its area
                if (grid[i][j] == 1) {
                    currentArea = 0;
                    getIslandArea(grid, currentArea, i, j);
                    maxArea = max(maxArea, currentArea);
                }
            }
        }
        return maxArea;
    }
    
    void getIslandArea(vector<vector<int>>& grid, int &area, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return;
        }
        grid[x][y] = 0;
        area++;
        getIslandArea(grid, area, x + 1, y);
        getIslandArea(grid, area, x - 1, y);
        getIslandArea(grid, area, x, y + 1);
        getIslandArea(grid, area, x, y - 1);

    }
};