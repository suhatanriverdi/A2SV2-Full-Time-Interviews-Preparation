// Question Link: https://leetcode.com/problems/get-equal-substrings-within-budget/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right = 0, size = s.size();
        vector<int> difs(size, 0);
        for (int i = 0; i < size; i++) {
            difs[i] = abs(s[i] - t[i]);
        }
        int tempSum = difs[0], result = 0;
        while (right < size) {
            if (tempSum <= maxCost) {
                result = max(result, right - left + 1);
                right++;
                if (right < size) {
                    tempSum += difs[right];
                }
            }
            else {
                tempSum -= difs[left];
                left++;
            }
        }
        return result;
    }
};
