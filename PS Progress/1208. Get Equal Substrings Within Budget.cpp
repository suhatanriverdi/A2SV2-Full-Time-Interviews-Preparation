// Question Link: https://leetcode.com/problems/get-equal-substrings-within-budget

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        int L = 0, R = 0;
        int cost = 0;
        int maxWindowLen = 0;
        while (R < len) {
            // If cost <= maxCost, Expand the window R++
            int diff = abs(s[R] - t[R]);
            if (cost + diff <= maxCost) {
                cost += diff;
                // Expand the window
                R++;
                // Update the window
                maxWindowLen = max(maxWindowLen, R - L);
            }
            // Else cost > maxCost, Shrink the window L++
            else {
                int diffLeft = abs(s[L] - t[L]);
                cost -= (cost - diffLeft >= 0 ? diffLeft : 0);
                // Shrink the window
                L++;
                // Update R, in case L >= R
                if (L > R) {
                    R = L;
                }
            }
        }
        return maxWindowLen;
    }
};
