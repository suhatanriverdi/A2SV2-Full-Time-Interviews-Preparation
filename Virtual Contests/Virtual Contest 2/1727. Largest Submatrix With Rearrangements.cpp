// Question Link: https://leetcode.com/problems/largest-submatrix-with-rearrangements

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[j][i] == 1) {
                    matrix[j][i] += matrix[j - 1][i];
                }
            }   
        }
        
        int largestArea = 0;
        for (vector<int> &row : matrix) {
            sort(begin(row), end(row), greater<int>());
            for (int i = 0, area; i < n; i++) {
                area = (i + 1) * row[i];
                largestArea = max(largestArea, area);
            }
        }
        
        return largestArea;
    }
};