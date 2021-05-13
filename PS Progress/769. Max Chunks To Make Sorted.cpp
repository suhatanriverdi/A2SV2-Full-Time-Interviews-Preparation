// Question Link: https://leetcode.com/problems/max-chunks-to-make-sorted/

class Solution {
public:
    int maxChunksToSorted(vector<int> &A) {
        int n = A.size(), answer = 0;
        if (n == 1) {
            return 1;
        }
        vector<vector<int>> unsortedIntervals, mergedIntervals;
        for (int i = 0; i < n; i++) {
            unsortedIntervals.push_back({min(i, A[i]), max(i, A[i])});
        }
        sort(begin(unsortedIntervals), end(unsortedIntervals));
        // Merge Intervals
        mergedIntervals = { unsortedIntervals[0] };
        for (int i = 1; i < unsortedIntervals.size(); i++) {
            // Overlapping intervals
            if (unsortedIntervals[i][0] >= mergedIntervals.back()[0] && unsortedIntervals[i][0] <= mergedIntervals.back()[1]) {
                // Merge intervals, overwrite existing one
                mergedIntervals.back() = {min(unsortedIntervals[i][0], mergedIntervals.back()[0]), max(unsortedIntervals[i][1], mergedIntervals.back()[1])};
            }
            else {
                mergedIntervals.push_back(unsortedIntervals[i]);
            }
        }
        answer += mergedIntervals.size();
        return answer;
    }
};