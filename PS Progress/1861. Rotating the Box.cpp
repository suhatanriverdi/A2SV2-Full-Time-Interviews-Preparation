// Question Link: https://leetcode.com/problems/rotating-the-box/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        // For each stone
        for (int col = n - 1; col >= 0; col--) {
            for (int row = 0; row < m; row++) {
                // Move current stone to as right side as possible
                if (box[row][col] == '#') {
                    int newCol = col + 1;
                    while (newCol < n && box[row][newCol] == '.') {
                        box[row][newCol - 1] = '.';
                        box[row][newCol] = '#';
                        newCol++;
                    }
                }
            }   
        }
        vector<vector<char>> rotatedBox(n, vector<char>(m, '.'));
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                rotatedBox[col][m - row - 1] = box[row][col];
            }
        }
        return rotatedBox;
    }
};