// Question Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// O(2 log n) Solution
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = { binarySearch(nums, target, true), binarySearch(nums, target, false) };
        return res;
    }
    
    int binarySearch(vector<int> &nums, int &target, bool first) {
        int l = 0, r = nums.size() - 1, mid;
        if (r + 1 == 0) {
            return -1;
        }
        while (r > l) {
            mid = (l + r) / 2;
            if (target == nums[mid]) {
                if (first == true) {
                    r = mid;
                } else {
                    l = mid;
                    if (l + 1 == r) {
                        if (nums[l] == nums[r]) {
                            l++;
                        }
                        break;
                    }
                }
            } 
            else if (target > nums[mid]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return (first ? ( (r >= 0 && nums[r] == target ? r : -1) ) : ( (nums[l] == target ? l : -1) ));
    }
};