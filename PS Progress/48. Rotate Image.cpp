// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int row = n - 1;
        int col = 0;
        // Start from left most corner
        while (row >= 0) {
            int upRow = row - 1;
            int rightCol = col + 1;
            // Swap up with right
            while (upRow >= 0) {
                swap(matrix[upRow][col], matrix[row][rightCol]);
                upRow--;
                rightCol++;
            }
            // Swap colums inside itself
            while (++upRow < (n / 2)) {
                swap(matrix[upRow][col], matrix[n - 1 - upRow][col]);
            }
            col++;
            row--;
        }
    }
};