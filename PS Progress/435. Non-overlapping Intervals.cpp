// Question Link: https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals acoording to the ending times
        auto comp = [](vector<int> &a, vector<int> &b) {
            if (a[1] < b[1]) {
                return true;
            }
            return false;
        };
        sort(begin(intervals), end(intervals), comp);
        int overlappingIntervals = 0;
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (isOverlapping(prev, intervals[i])) {
                overlappingIntervals++;
            }
            // Update current interval
            else {
                prev = intervals[i];
            }
        }
        return overlappingIntervals;
    }
    
    bool isOverlapping(vector<int> &prev, vector<int> &cur) {
        if (prev[1] > cur[0]) {
            return true;
        }
        return false;
    }
};