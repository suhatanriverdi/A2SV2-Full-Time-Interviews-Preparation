// Question Link: https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, mid, ver;
        while (l < r) {
            // Overcoming Overflow, Don't use (l + r) / 2 -> this will overflow
            mid = l + (r - l) / 2, ver = isBadVersion(mid);
            // If current version is bad, look for left
            if (ver == true) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }
};