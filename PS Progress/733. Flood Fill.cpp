// Question Link: https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor != newColor) {
            dfs(image, sr, sc, oldColor, newColor);
        }
        return image;
    }
    
    void dfs(vector<vector<int>> &image, int x, int y, int &oldColor, int &newColor) {
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != oldColor) {
            return;
        }
        image[x][y] = newColor;
        dfs(image, x + 1, y, oldColor, newColor);
        dfs(image, x - 1, y, oldColor, newColor);
        dfs(image, x, y + 1, oldColor, newColor);
        dfs(image, x, y - 1, oldColor, newColor);
    }
};
