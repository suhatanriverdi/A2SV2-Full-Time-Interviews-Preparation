// Question Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        int result = 0, size = A.size();
        for (int i = 0; i < size; i++) {
            int start = A[i][0];
            int end = A[i][1];
            int j = i + 1;
            int checkStart = (j < size) ? (A[j][0]) : size;
            int checkEnd = (j < size) ? (A[j][1]) : size;
            // As long as overlapping balloons are found
            while (j < size && start <= checkStart && checkStart <= end) {
                // Update pivot interval
                start = max(start, checkStart);
                end = min(end, checkEnd);
                // Go to the next balloon
                j++;
                // Update the next balloon's start point
                checkStart = (j < size) ? (A[j][0]) : size;
                checkEnd = (j < size) ? (A[j][1]) : size;
                if (j >= size) {
                    break;
                }
            }
            // Continue processing from the last balloon where we left
            i = j;
            i--;
            result++;
        }
        return result;
    }
};