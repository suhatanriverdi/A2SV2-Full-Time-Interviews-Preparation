// Question Link: https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroIndex = 0, twoIndex = nums.size() - 1, i = 0;
        while (i < nums.size() && twoIndex >= i) {
            // If 0, move to the front
            if (nums[i] == 0) {
                swap(nums[i], nums[zeroIndex++]);
                if (zeroIndex > i) {
                    i = zeroIndex;
                }
            }
            // If 2, move to the end
            else if (nums[i] == 2) {
                swap(nums[i], nums[twoIndex--]);
            } 
            else {
                i++;
            }
        }
    }
};