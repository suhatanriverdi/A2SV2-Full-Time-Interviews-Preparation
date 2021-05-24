// Question Link: https://leetcode.com/problems/remove-covered-intervals/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        int n = in.size(), covereds = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = in[i][0], b = in[i][1];
                int c = in[j][0], d = in[j][1];
                // If not covered before
                if (a != -1 || c != -1) {
                    // [a,b) is covered by interval [c,d) if and only if c <= a and b <= d
                    if (c <= a && b <= d) {
                        // Mark that interval as aslready covered
                        in[i][0] = -1;
                        in[i][1] = -1;
                        covereds++;
                    }
                    // [c,d) is covered by interval [a,b) if and only if a <= c and d <= b
                    else if (c >= a && b >= d) {
                        in[j][0] = -1;
                        in[j][1] = -1;
                        covereds++;
                    }
                }
            }
        }
        return n - covereds;
    }
};