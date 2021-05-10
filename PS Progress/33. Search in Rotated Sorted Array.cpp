// Question Link: https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1, M;
        while (L <= R) {
            M = (L + R) / 2;
            if (nums[M] == target) {
                return M;
            }
            // If Left is sorted
            if (nums[L] <= nums[M]) {
                // If the target lays on the left part
                if (nums[L] <= target and target <= nums[M]) {
                    R = M - 1;
                } 
                else {
                    L = M + 1;
                }
            }
            // If Right is sorted
            else {
                // If the target lays on the right part
                if (nums[M] <= target and target <= nums[R]) {
                    L = M + 1;
                } 
                else {
                    R = M - 1;
                }
            }
        }   
        return -1;
    }
};