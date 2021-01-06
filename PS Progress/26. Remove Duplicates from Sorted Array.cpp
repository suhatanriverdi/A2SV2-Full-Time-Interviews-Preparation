// Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return size;
        }
        int prevIdx = 0, i = 1;
        while (i < size) {
            if (nums[prevIdx] != nums[i]) {
                prevIdx++;
                i++;
            } 
            else {
                while (i < size && nums[prevIdx] == nums[i]) {
                    i++;
                }
                if (i < size) {
                    nums[++prevIdx] = nums[i];
                }
                else {
                    break;
                }
            }
        }
        return ++prevIdx;
    }
};
