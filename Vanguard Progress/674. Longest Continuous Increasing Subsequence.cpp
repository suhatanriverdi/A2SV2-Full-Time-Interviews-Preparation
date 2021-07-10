// Question Link: https://leetcode.com/problems/longest-continuous-increasing-subsequence/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int result = 1;
        for (int i = 1, len = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                len++;
                result = max(result, len);
            }
            else {
                len = 1;
            }
        }
        return result;
    }
};