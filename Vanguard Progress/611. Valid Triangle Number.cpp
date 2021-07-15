// Question https://leetcode.com/problems/valid-triangle-number/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int count = 0, len = nums.size(), wanted;
        for (int i = 0; i < len - 2; i++) {
            for (int j = i + 1; j < len - 1; j++) {
                wanted = nums[i] + nums[j];
                int index = binarySearch(wanted, j + 1, len, nums);
                if (index != -1) {
                    count += index - 1 - j;
                }
            }
        }
        return count;
    }
    
    // Return the left most number "c" such that a + b > c, return -1 otherwise
    int binarySearch(int target, int start, int &len, vector<int> &nums) {
        int l = start, r = len, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};