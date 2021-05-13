// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return intervals;
        }
        sort(begin(intervals), end(intervals));
        vector<vector<int>> result = { intervals[0] };
        // Merge Intervals
        for (int i = 1; i < intervals.size(); i++) {
            // Overlapping intervals
            if (intervals[i][0] >= result.back()[0] && intervals[i][0] <= result.back()[1]) {
                // Merge intervals, overwrite existing one
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};