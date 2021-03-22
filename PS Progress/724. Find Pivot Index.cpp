// Question Link: https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        int totalSum = nums.back();
        for (int i = 0, lSum = 0, rSum; i < nums.size(); i++) {
            rSum = totalSum - nums[i];
            if (lSum == rSum) {
                return i;
            }
            lSum = nums[i];
        }
        return -1;
    }
};
