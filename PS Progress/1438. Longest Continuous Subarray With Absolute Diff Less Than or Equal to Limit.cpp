// Question Link: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int L = 0, R = 0, size = nums.size(), longestSubArrLen = 0;
        map<int, int> window = { {nums[0], 1} };
        while (R < size) {
            int miN = window.begin()->first;
            int maX = (--window.end())->first;
            // Check if abs(max - min) <= limit, expand subarray
            if (maX - miN <= limit) {
                longestSubArrLen = max(longestSubArrLen, R - L + 1);
                R++;
                if (R < size) {
                    window[nums[R]]++;
                }
            }
            // Shrink subarray
            else {
                window[nums[L]]--;
                if (window[nums[L]] == 0) {
                    window.erase(nums[L]);
                }
                L++;
            }
        }
        return longestSubArrLen;
    }
};