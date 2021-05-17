// Question Link: https://leetcode.com/problems/rotating-the-box/

// Solution 2 | Reflect Changes To Rotated Box
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        // Rotated box
        vector<vector<char>> rotatedBox(n, vector<char>(m, ','));
        // For each stone
        for (int col = n - 1; col >= 0; col--) {
            for (int row = 0; row < m; row++) {
                // Move current stone to as right side as possible
                if (box[row][col] == '#') {
                    // Reflect changes to new box as well
                    rotatedBox[col][m - row - 1] = '#';
                    int newCol = col + 1;
                    bool moved = false;
                    while (newCol < n && box[row][newCol] == '.') {
                        box[row][newCol - 1] = '.';
                        box[row][newCol] = '#';
                        // Reflect changes to new box as well
                        rotatedBox[newCol - 1][m - row - 1] = '.';
                        rotatedBox[newCol][m - row - 1] = '#';
                        newCol++;
                    }
                }
                else {
                    rotatedBox[col][m - row - 1] = box[row][col];
                }
            }   
        }
        return rotatedBox;
    }
};

// Solution 1
// We basically move the stones to the right as if we are rotating the box 90 degree clock-wise
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
