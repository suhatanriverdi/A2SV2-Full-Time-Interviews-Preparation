// Question Link: https://leetcode.com/problems/non-decreasing-array

// Solution With Sorting
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if ((i - 2 < 0)) {
                    nums[i - 1] = nums[i];
                } else {
                    if (nums[i - 2] <= nums[i]) {
                        nums[i - 1] = nums[i - 2];
                    } else {
                        nums[i] = nums[i - 1];
                    }
                }
                break;
            }
        }
        vector<int> increasing = nums;
        // After modifying, sorted(increasing) array should be equal to modified version
        // If it is a non-decreasing array
        sort(begin(increasing), end(increasing));
        return (increasing == nums);
    }
};

// Solution Without Sorting
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for (int i = 1, count = 0; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if ((i - 2 < 0)) {
                    nums[i - 1] = nums[i];
                } else {
                    if (nums[i - 2] <= nums[i]) {
                        nums[i - 1] = nums[i - 2];
                    } else {
                        nums[i] = nums[i - 1];
                    }
                }
                count++;
            }
            if (count > 1) {
                return false;
            }
        }
        return true;
    }
};