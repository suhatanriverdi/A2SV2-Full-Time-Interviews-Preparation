// Question Link: https://leetcode.com/problems/minimum-time-difference/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for (string &t : timePoints) {
            int h1 = (t[0] - '0') * 10, h2 = t[1] - '0';
            int m1 = (t[3] - '0') * 10, m2 = t[4] - '0';
            int hourToMinute = ((h1 + h2) * 60);
            int minutes = m1 + m2;
            int totalMinute = hourToMinute + minutes;
            mins.push_back((totalMinute == 0 ? 1440 : totalMinute));
        }
        int minDiff = INT_MAX;
        sort(begin(mins), end(mins));
        for (int i = 1, diff, diffMidnight; i < mins.size(); i++) {
            diff = mins[i] - mins[i - 1];
            diffMidnight = 1440 - mins[i] + mins[i - 1];
            minDiff = min(diff, min(minDiff, diffMidnight));
        }
        int diffMidnight = 1440 - mins.back() + mins[0];
        minDiff = min(minDiff, diffMidnight);
        return minDiff;
    }
};
