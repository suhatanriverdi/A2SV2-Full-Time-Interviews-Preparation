// Question Link: https://leetcode.com/problems/longest-turbulent-subarray/

// A bit improvent
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size(), result = 1;
        if (len == 1) {
            return 1;
        }
        int cur = getVal(arr[1], arr[0]);
        int flip = cur;
        int windowLen = 1;
        for (int R = 1; R < len; R++) {
            cur = getVal(arr[R], arr[R - 1]);
            if (arr[R] == arr[R - 1]) {
                windowLen = 1;
                flip = cur;
                continue;
            }
            if (flip == cur) {
                flip *= -1;
                windowLen++;
                result = max(result, windowLen);
            }
            else {
                windowLen = 1;
                flip = cur;
                R--;
            }
        }
        return result;
    }
    
    int getVal(int cur, int prev) {
        return (cur > prev) ? 1 : ((cur < prev) ? -1 : 0);
    }
};

// Initial solution
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size(), result = 1;
        if (len == 1) {
            return 1;
        }
        int cur = getVal(arr[1], arr[0]);
        int flip = cur;
        int windowLen = 1;
        for (int R = 1; R < len; R++) {
            cur = getVal(arr[R], arr[R - 1]);
            if (arr[R] == arr[R - 1]) {
                result = max(result, windowLen);
                windowLen = 1;
                flip = cur;
                continue;
            }
            if (flip == cur) {
                flip *= -1;
                windowLen++;
            }
            else {
                result = max(result, windowLen);
                windowLen = 1;
                flip = cur;
                R--;
            }
        }
        result = max(result, windowLen);
        return result;
    }
    
    int getVal(int cur, int prev) {
        return (cur > prev) ? 1 : ((cur < prev) ? -1 : 0);
    }
};