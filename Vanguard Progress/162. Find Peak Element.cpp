// Question https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size(), l = 0, r = len - 1;
        int mid, mL, mR;
        while (l <= r) {
            mid = l + (r - l) / 2;
            mL = (mid - 1 < 0) ? INT_MIN : nums[mid - 1];
            mR = (mid + 1 >= len) ? INT_MAX : nums[mid + 1];
            if (nums[mid] > mL && nums[mid] > mR) {
                return mid;
            }
            if (mL > mR) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return mid;
    }
};