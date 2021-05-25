// Question Link: https://leetcode.com/problems/remove-covered-intervals/

// Time: O(nlogn)
// Space: O(n)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        // Sort them by their starting points
        sort(begin(in), end(in), [](vector<int> &a, vector<int> &b){
            if (a[0] < b[0]) {
                return true;
            }
            if (a[0] == b[0]) {
                return ((a[1] - a[0]) >= (b[1] - b[0]));
            }
            return false;
        });
        // Hold the end points
        set<int> endings = { in[0][1] };
        int n = in.size(), numOfcovereds = 0;
        for (int i = 1; i < n; i++) {
            int b = in[i][1];
            auto it = endings.lower_bound(b);
            // Current is covered by one of the previous intervals
            if (it != endings.end() && *it >= b) {
                numOfcovereds++;
            }
            endings.insert(b);
        }
        return n - numOfcovereds;
    }
};