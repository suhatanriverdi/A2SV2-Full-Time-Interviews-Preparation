// Question Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

// O(m + n) Solution
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int negativesCount = 0, L = 0;
        for (int curRow = row - 1; curRow >= 0; curRow--) {
            // Update Left pointer as long as we see positive number
            while (L < col && grid[curRow][L] >= 0) {
                L++;
            }
            // Get the negative number count for current row
            if (L < col) {
                negativesCount += col - L;
            }
        }
        return negativesCount;
    }
};

// O(m log n) Solution
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int negativesCount = 0, negativeIndex;
        for (vector<int> &row : grid) {
            negativeIndex = binarySearch(row);
            negativesCount += row.size() - (negativeIndex == -1 ? row.size() : negativeIndex);
        }
        return negativesCount;
    }
    
    // Check for where the negative numbers starts
    int binarySearch(vector<int> &row) {
        int l = 0, r = row.size() - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (row[mid] >= 0) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return (row[r] >= 0 ? -1 : r);
    }
};